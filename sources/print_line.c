/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 10:47:27 by acollin           #+#    #+#             */
/*   Updated: 2014/03/21 18:00:26 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "line_editor_static.h"
#include <term.h>
#include <ncurses.h>
#include <unistd.h>
#include "actions.h"
#include <sys/ioctl.h>

void				print_line_remove(t_edited_line *line)
{
	char			*letter;
	t_atom			*tmp_curr;

	tputs(tgetstr("cd", NULL), 1, ft_outc);
	tputs(tgetstr("sc", NULL), 1, ft_outc);
	tmp_curr = line->data->curr;
	while ((letter = ft_lst_next_content(line->data)))
		ft_putchar(*letter);
	line->data->curr = tmp_curr;
	tputs(tgetstr("rc", NULL), 1, ft_outc);
}

void				print_line(t_edited_line *line)
{
	char			*letter;
	int				curr_pos;
	int				curr_mod;
	t_atom			*tmp_curr;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	display_prompt(line->prompt);
	tmp_curr = line->data->curr;
	line->data->curr = NULL;
	while ((letter = ft_lst_next_content(line->data)))
		ft_putchar(*letter);
	ft_lst_prev_content(line->data);
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_mod = curr_pos % win.ws_col;
	line->data->curr = tmp_curr;
	if (!curr_mod && tmp_curr == line->data->last)
	{
		tputs(tgetstr("do", NULL), 1, ft_outc);
		tputs(tgetstr("cr", NULL), 1, ft_outc);
	}
}
