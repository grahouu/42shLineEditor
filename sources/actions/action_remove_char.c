/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_remove_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:55:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 15:16:28 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <stdlib.h>
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

void		remove_previous_char(t_edited_line *line)
{
	t_atom	*new_curr;

	if (line->data->curr)
	{
		new_curr = line->data->curr->prev;
		ft_lst_del_atom(line->data, line->data->curr, &free);
		line->data->curr = new_curr;
		tputs(tgetstr("le", NULL), 1, ft_outc);
		tputs(tgetstr("dc", NULL), 1, ft_outc);
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
