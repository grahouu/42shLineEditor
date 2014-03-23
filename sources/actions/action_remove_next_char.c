/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_remove_next_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:55:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/22 19:50:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
#include <stdlib.h>
#include <term.h>

static void		reposition_begin(t_edited_line *line)
{
	int			curr_nbline;

	line->info->nb_char--;
	calcul_info(line);
	curr_nbline = line->info->curr_pos / line->info->col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
	tputs(tgetstr("cd", NULL), 1, ft_outc);
	ft_lst_next_content(line->data);
	ft_lst_del_atom(line->data, line->data->curr, &free);
	calcul_info(line);
}

void			remove_next_char(t_edited_line *line)
{
	t_atom		*tmp_curr;

	reposition_begin(line);
	tmp_curr = line->data->curr;
	print_line(line);
	if (line->data->curr != line->data->last)
	{
		if (!line->info->last_mod)
		{
			if (line->data->curr == line->data->last->prev)
			{
				tputs(tgetstr("le", NULL), 1, ft_outc);
				tputs(tgetstr("nd", NULL), 1, ft_outc);
			}
			line->data->curr = line->data->last;
			ft_lst_prev_content(line->data);
		}
		else
			line->data->curr = line->data->last;
		while (line->data->curr != tmp_curr)
			move_cursor_left(line);
	}
}
