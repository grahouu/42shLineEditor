/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:10:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/13 23:51:40 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

void				action_add_char(int letter, t_edited_line *line)
{
	char			*new_char;

	new_char = (char*)malloc(sizeof(char));
	*new_char = (char)letter;
	if (line->curs_pos == 0)
	{

		ft_lst_push(line->data, new_char);
		if (line->data->curr && line->data->curr->prev)
			ft_lst_prev_content(line->data);
		else
			ft_lst_next_content(line->data);
	}
	else
	{
		ft_lst_push_after_curr(line->data, new_char);
		ft_lst_next_content(line->data);
	}
	line->curs_pos++;
	line->len_old_line = line->len_line;
	line->len_line++;
	print_line(line);
	tputs(tgetstr("nd", NULL), 1, ft_outc);
	disable_escape(line);
}
