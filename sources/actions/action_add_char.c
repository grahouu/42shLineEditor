/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:10:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 18:02:16 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "actions.h"
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

static void				reposition_begin(t_edited_line *line)
{
	int				curr_nbline;

	curr_nbline = (line->info->curr_pos - 1) / line->info->col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
}

void				reposition_cursor_curr(t_edited_line *line)
{
	int				nb_le;

	calcul_info(line);
	nb_le = line->info->len_line - line->info->curr_pos;
	while (nb_le--)
		tputs(tgetstr("le", NULL), 1, ft_outc);
}

void				action_add_char(int letter, t_edited_line *line)
{
	char			*new_char;

	new_char = (char*) malloc(sizeof(char));
	*new_char = (char) letter;
	ft_lst_push_after_curr(line->data, new_char);
	ft_lst_next_content(line->data);
	calcul_info(line);
	line->info->nb_char++;
	if ((!line->info->last_mod && line->data->curr == line->data->last
			&& line->info->max_char <= line->info->len_line)
		|| (line->info->max_char < line->info->len_line
		&& line->info->last_mod == 1 && line->data->curr != line->data->last))
		line->info->nb_char = line->info->nb_char - line->info->col;
	reposition_begin(line);
	print_line(line);
	if (line->info->curr_pos > line->info->min_char)
		reposition_cursor_curr(line);
	else
		line->data->curr = line->data->last;
	disable_escape(line);
}
