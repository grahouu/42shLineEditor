/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:35:35 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 16:39:22 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include <stdlib.h>
#include <unistd.h>

char				*list_to_string(t_list *line)
{
	char			*string;
	char			*current;
	char			*letter;

	string = (char*)malloc((line->len + 1) * sizeof(char));
	if (string)
	{
		current = string;
		line->curr = NULL;
		while ((letter = (char*)ft_lst_next_content(line)))
		{
			*current = *letter;
			current++;
		}
		*current = 0;
	}
	ft_lst_del(line, &free);
	return (string);
}
