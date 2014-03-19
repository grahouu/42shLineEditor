/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reposition_cursor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 14:48:03 by acollin           #+#    #+#             */
/*   Updated: 2014/03/19 09:44:29 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include <sys/ioctl.h>
#include <term.h>
#include <unistd.h>

void				reposition_cursor_begin(t_edited_line *line, int flag)
{
	int				pos_curr;
	int				curr_mod;
	int				curr_nbline;
	struct winsize	win;

	debug("---------- REPOSITION DU CURSEUR ----------");
	ioctl(0, TIOCGWINSZ, &win);
	pos_curr = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_nbline = (pos_curr) / win.ws_col;
	curr_mod = pos_curr % win.ws_col;
	if (flag == 1)
	{
		if (!curr_nbline && (curr_mod == (win.ws_col - 1)))
			curr_nbline = 1;
		else if (curr_nbline && (curr_mod == (win.ws_col - 1)))
			curr_nbline++;
	}
	else if (flag == 2)
	{
		if (curr_mod == 0)
			curr_nbline--;
	}
	else
		curr_nbline = (pos_curr - 1) / win.ws_col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
//	usleep(80000);
}

void				reposition_cursor_curr(t_edited_line *line)
{
	int				len_line;
	int				pos_x;
//	char			*letter;
	t_atom			*tmp_atom;
	int				test;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	len_line = line->data->len + line->len_prompt;
	pos_x = ((ft_lst_curr_index(line->data) + line->len_prompt) % win.ws_col);
	test = line->data->len - ft_lst_curr_index(line->data);
//	display_prompt(line->prompt);
	tmp_atom = line->data->curr;
//	line->data->curr = NULL;
	while (test--)
		tputs(tgetstr("le", NULL), 1, ft_outc);
/*	while (line->data->curr != tmp_atom)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		letter = ft_lst_next_content(line->data);
		ft_putchar(*letter);
	}*/
/*	if (pos_x == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_outc);
		tputs(tgetstr("cr", NULL), 1, ft_outc);
	}*/
}
