/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/22 15:40:04 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include "actions.h"
#include <term.h>

void				cursor_reposition_curr(t_edited_line *line)
{
	calcul_info(line);
	tputs(tgetstr("nd", NULL), 1, ft_outc);
	if (!line->info->curr_mod)
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
