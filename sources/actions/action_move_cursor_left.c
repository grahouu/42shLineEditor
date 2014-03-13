/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:45:10 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 00:06:19 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>

static void		in_list(t_list *data)
{
	if (data->curr->prev)
		ft_lst_prev_content(data);
}

static void		in_display(t_edited_line *line)
{
	if (line->curs_pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		line->curs_pos--;
	}
}

void			move_cursor_left(t_edited_line *line)
{
	if (line->data->curr)
	{
		in_list(line->data);
		in_display(line);
	}
}
