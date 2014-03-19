/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/19 09:11:30 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "libft.h"
#include "actions.h"
#include <term.h>
#include <sys/ioctl.h>

void				move_cursor_left(t_edited_line *line)
{
	ft_lst_prev_content(line->data);
	if (line->data->curr != line->data->last)
		reposition_cursor_curr(line, 1);
	else
		ft_lst_next_content(line->data);
}
