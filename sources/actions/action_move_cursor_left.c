/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/23 14:49:45 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include "actions.h"
#include <term.h>

void				move_cursor_left(t_edited_line *line)
{
	calcul_info(line);
	if (line->info->curr_pos > line->info->min_char)
	{
		if (line->data->curr == line->data->last && !line->info->curr_mod)
		{
			tputs(tgetstr("up", NULL), 1, ft_outc);
			tputs(tgoto(tgetstr("ch", NULL), 0, line->info->col), 1, ft_outc);
			ft_lst_prev_content(line->data);
		}
		else if (line->data->curr)
		{
			tputs(tgetstr("le", NULL), 1, ft_outc);
			ft_lst_prev_content(line->data);
		}
	}
}
