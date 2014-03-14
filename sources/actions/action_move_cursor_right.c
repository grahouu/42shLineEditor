/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 14:52:46 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>

static void		in_list(t_edited_line *line)
{
	if (line->data->curr != line->data->last)
		ft_lst_next_content(line->data);
}

void			move_cursor_right(t_edited_line *line)
{
	if (line->data->curr != line->data->last)
	{
		in_list(line);
		tputs(tgetstr("nd", NULL), 1, ft_outc);
	}
}
