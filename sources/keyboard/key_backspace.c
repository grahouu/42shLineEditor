/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_backspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:23:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 18:17:21 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "actions.h"

int			key_backspace_event(t_edited_line *line)
{
	if (line->data->curr)
	{
		if (line->esc_key)
		{
			remove_previous_word(line);
			line->esc_key = 0;
		}
		else
			remove_previous_char(line);
	}
	return (EDITED_GOON);
}
