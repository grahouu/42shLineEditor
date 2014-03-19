/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:10:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/19 09:10:19 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void static			reposition_begin(t_edited_line *line)
{
	int				curr_nbline;
	int				pos_curr;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	pos_curr = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_nbline = (pos_curr - 1) / win.ws_col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
	sleep(1);
}

void				action_add_char(int letter, t_edited_line *line)
{
	char			*new_char;

	new_char = (char*) malloc(sizeof(char));
	*new_char = (char) letter;
	ft_lst_push_after_curr(line->data, new_char);
	ft_lst_next_content(line->data);
	print_line(line);
	reposition_begin(line);
	reposition_cursor_curr(line);
	disable_escape(line);
}
