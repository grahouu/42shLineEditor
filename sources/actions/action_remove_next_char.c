/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_remove_next_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:55:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 02:35:08 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
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

void		remove_next_char(t_edited_line *line)
{
	move_cursor_right(line);
	remove_previous_char(line);
}

void		remove_next_word(t_edited_line *line)
{
	char	c;

	c = *(char*)line->data->curr->content;
	if (!is_space(c) && !is_correct_word_char(c))
		remove_next_char(line);
	else
	{
		while (line->data->curr
			&& is_space(*(char*)line->data->curr->next->content))
			remove_next_char(line);
		while (line->data->curr
			&& is_correct_word_char(*(char*)line->data->curr->next->content))
			remove_next_char(line);
	}
}
