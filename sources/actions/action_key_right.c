/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:11:06 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 21:51:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <ncurses.h>

static void		in_list(t_edited_line *line)
{
	if (line->curs_pos > 1 && line->data->curr->next)
		ft_lst_next_content(line->data);
}

static void		in_display(t_edited_line *line)
{
	if (line->curs_pos < line->len_line)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		line->curs_pos++;
	}
}

void			action_key_right(t_edited_line *line)
{
	if (line->data->curr)
	{
		in_list(line);
		in_display(line);
	}
}
