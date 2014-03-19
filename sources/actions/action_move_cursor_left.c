/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 19:05:23 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include "actions.h"
#include <term.h>
#include <sys/ioctl.h>

/*void static			repostion_begin(t_edited_line *line)
{
	int				curr_nbline;
	int				curr_pos;
	int				curr_mod;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_nbline = curr_pos / win.ws_col;
	curr_mod = curr_pos % win.ws_col;
	if (!curr_nbline && (curr_mod == (win.ws_col - 1)))
		curr_nbline = 1;
	else if (curr_nbline && (curr_mod == (win.ws_col - 1)))
		curr_nbline++;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
}*/

/*void static			cursor_reposition_curr(t_edited_line *line)
{
	int				curr_nbline;
	int				curr_pos;
	int				curr_mod;
	struct winsize	win;

	tputs(tgetstr("le", NULL), 1, ft_outc);
	ioctl(0, TIOCGWINSZ, &win);
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_nbline = curr_pos / win.ws_col;
	curr_mod = curr_pos % win.ws_col;
	if (curr_mod == (win.ws_col - 1))
	{
		tputs(tgetstr("up", NULL), 1, ft_outc);
		while (curr_mod--)
			tputs(tgetstr("nd", NULL), 1, ft_outc);
	}
}*/

void				move_cursor_left(t_edited_line *line)
{
	int				curr_pos;
	int				max_char;
	int				nb_aff;
	int				curr_mod;
	int				last_mod;
	int				char_min;
	int				nb_line;
	int				nb_line_min;
	struct winsize	win;

	debug("---------- MOVE LEFT ----------");
	ioctl(0, TIOCGWINSZ, &win);
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	max_char = win.ws_col * win.ws_row;
	curr_mod = curr_pos % win.ws_col;
	last_mod = line->data->len % win.ws_col;
	nb_aff = (line->len_prompt + line->data->len) - (max_char - last_mod - win.ws_col) - curr_pos ;
	//nb_aff = (line->len_prompt + line->data->len) - max_char - curr_pos;
	char_min = line->data->len + line->len_prompt - line->win_nbchar;
	nb_line = curr_pos / win.ws_col;
	nb_line_min = (line->data->len - max_char) / win.ws_col;
	debug("->CHAR_MIN");
	debug_int(char_min);
	debug("->CURR_POS");
	debug_int(curr_pos);
	debug("->WIN_NBCHAR");
	debug_int(line->win_nbchar);
/*	debug("->NB_LINE");
	debug_int(nb_line);
	debug("->NB_LINE_MIN");
	debug_int(nb_line_min);*/
	if (curr_pos > char_min)
	{
//		ft_lst_prev_content(line->data);
		if (line->data->curr == line->data->last && !curr_mod)
		{
			tputs(tgetstr("up", NULL), 1, ft_outc);
			tputs(tgoto(tgetstr("ch", NULL), 0, win.ws_col), 1, ft_outc);
			ft_lst_prev_content(line->data);
		}
		else if (line->data->curr/*&& (line->data->curr != line->data->first)*/)
		{
			debug("CURR OK");
			tputs(tgetstr("le", NULL), 1, ft_outc);
			ft_lst_prev_content(line->data);
		}
		else
			debug("CURR NULL");
	}
}
