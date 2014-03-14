/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move_cursor_word.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 02:12:40 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 02:24:38 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <actions.h>

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

void		move_cursor_word_right(t_edited_line *line)
{
	char	c;

	c = *(char*)line->data->curr->content;
	if (!is_space(c) && !is_correct_word_char(c))
		move_cursor_right(line);
	else
	{
		while (line->data->curr
			&& is_space(*(char*)line->data->curr->content))
			move_cursor_right(line);
		while (line->data->curr
			&& is_correct_word_char(*(char*)line->data->curr->content))
			move_cursor_right(line);
	}
}

void		move_cursor_word_left(t_edited_line *line)
{
	char	c;

	c = *(char*)line->data->curr->content;
	if (!is_space(c) && !is_correct_word_char(c))
		move_cursor_left(line);
	else
	{
		while (line->data->curr
			&& is_space(*(char*)line->data->curr->content))
			move_cursor_left(line);
		while (line->data->curr
			&& is_correct_word_char(*(char*)line->data->curr->content))
			move_cursor_left(line);
	}
}
