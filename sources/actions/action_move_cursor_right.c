/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 19:05:11 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include "actions.h"
#include <term.h>
#include <sys/ioctl.h>

void				cursor_reposition_curr(t_edited_line *line)
{
	int				curr_mod;
	int				curr_pos;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	curr_mod = curr_pos % win.ws_col;
	tputs(tgetstr("nd", NULL), 1, ft_outc);
	if (!curr_mod)
	{
		tputs(tgetstr("do", NULL), 1, ft_outc);
		tputs(tgetstr("cr", NULL), 1, ft_outc);
	}
}


void				move_cursor_right(t_edited_line *line)
{
	ft_lst_next_content(line->data);
	if (line->data->curr)
		cursor_reposition_curr(line);
	else
		ft_lst_prev_content(line->data);
}
