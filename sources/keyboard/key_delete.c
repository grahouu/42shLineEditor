/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:23:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 17:23:29 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>

int			key_delete_event(t_edited_line *line)
{
	if (line->data->curr != line->data->last)
	{
		if (line->esc_key)
		{
			remove_next_word(line);
			line->esc_key = 0;
		}
		else
			remove_next_char(line);
	}
	return (1);
}
