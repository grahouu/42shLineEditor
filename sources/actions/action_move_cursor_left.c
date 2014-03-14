/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 14:51:02 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include <term.h>
#include <stdio.h>

static void		in_list(t_list *data)
{
	if (data->curr)
		ft_lst_prev_content(data);
}

void			move_cursor_left(t_edited_line *line)
{
	if (line->data->curr)
	{
		in_list(line->data);
		tputs(tgetstr("le", NULL), 1, ft_outc);
	}
}
