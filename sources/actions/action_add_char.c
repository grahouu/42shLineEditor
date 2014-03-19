/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:10:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/19 19:05:29 by acollin          ###   ########.fr       */
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
}

void				action_add_char(int letter, t_edited_line *line)
{
	char			*new_char;
	int				max_char;
	int				curr_mod;
	int				char_min;
	int				curr_pos;
	struct winsize	win;

	debug("---------- ACTION ADD CHAR ----------");
	ioctl(0, TIOCGWINSZ, &win);
	new_char = (char*) malloc(sizeof(char));
	*new_char = (char) letter;
	ft_lst_push_after_curr(line->data, new_char);
	ft_lst_next_content(line->data);
	line->win_nbchar++;
	max_char = win.ws_col * win.ws_row;
	curr_mod = (line->data->len + line->len_prompt) % win.ws_col;
	debug("->CURR_MOD");
	debug_int(curr_mod);
	debug("->MAX_CHAR");
	debug_int(max_char);
	if ((!curr_mod && (line->data->curr == line->data->last) && (max_char <= (int)(line->data->len + line->len_prompt)))
		|| (max_char < (int)(line->data->len + line->len_prompt) && curr_mod == 1 && line->data->curr != line->data->last))
		line->win_nbchar = line->win_nbchar - win.ws_col;
	char_min = line->data->len + line->len_prompt - line->win_nbchar;
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	debug("->WIN_NBCHAR");
	debug_int(line->win_nbchar);
	reposition_begin(line);
	print_line(line);
	if (curr_pos > char_min)
		reposition_cursor_curr(line);
	else
		line->data->curr = line->data->last;
	disable_escape(line);
}
