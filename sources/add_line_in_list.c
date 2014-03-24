/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:37:16 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 17:00:18 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include <stdlib.h>

void				add_line_in_list(t_edited_line *line, char *newdata)
{
	char			*oldline;

	if (newdata && line->option->mode == NORMAL_MODE)
	{
		ft_lst_pushend(line->option->historic, newdata);
		line->option->historic->curr = NULL;
	}
	else if (newdata && line->option->mode == NOFINISH_MODE)
	{
		oldline = line->option->historic->last->content;
		line->option->historic->last->content = ft_strjoin(oldline, newdata, 0);
		free(oldline);
	}
}
