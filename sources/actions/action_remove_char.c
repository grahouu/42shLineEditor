/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_remove_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:55:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/22 19:50:54 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "actions.h"
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

static int	is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

static int	is_correct_word_char(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void		print_line_remove(t_edited_line *);

static void				reposition_begin(t_edited_line *line)
{
	int				curr_nbline;

	calcul_info(line);
	curr_nbline = line->info->curr_pos / line->info->col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
}

void		remove_previous_char(t_edited_line *line)
{
	t_atom		*tmp_curr;

	if (line->data->curr)
	{
		line->info->nb_char--;
		reposition_begin(line);
		tputs(tgetstr("cd", NULL), 1, ft_outc);
		ft_lst_del_atom(line->data, line->data->curr, &free);
		calcul_info(line);
		tmp_curr = line->data->curr;
		print_line(line);
		if (line->data->curr != line->data->last)
		{
			if (!line->info->last_mod)
			{
				line->data->curr = line->data->last;
				ft_lst_prev_content(line->data);
			}
			else
				line->data->curr = line->data->last;
			while (line->data->curr != tmp_curr)
				move_cursor_left(line);
		}
	}
}

void		remove_previous_word(t_edited_line *line)
{
	char	c;

	c = *(char*)line->data->curr->content;
	if (!is_space(c) && !is_correct_word_char(c))
		remove_previous_char(line);
	else
	{
		while (line->data->curr
			&& is_space(*(char*)line->data->curr->content))
			remove_previous_char(line);
		while (line->data->curr
			&& is_correct_word_char(*(char*)line->data->curr->content))
			remove_previous_char(line);
	}
}
