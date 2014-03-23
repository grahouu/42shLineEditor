/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_editedline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 16:16:31 by acollin           #+#    #+#             */
/*   Updated: 2014/03/23 16:27:02 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"

static t_edited_line		*global_line(t_edited_line *new_line)
{
	static t_edited_line	*line;

	if(new_line != NULL)
		line = new_line;
	return (line);
}

void						set_edited_line(t_edited_line *new_line)
{
	global_line(new_line);
}

t_edited_line				*get_edited_line(void)
{
	return (global_line(NULL));
}
