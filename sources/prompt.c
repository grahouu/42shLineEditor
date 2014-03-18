/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 18:34:19 by acollin           #+#    #+#             */
/*   Updated: 2014/03/15 12:37:15 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prompt.h"
#include "line_editor_static.h"

t_prompt	*prompt_new(char *line)
{
	t_prompt	*prompt;

	if (!(prompt = (t_prompt *) malloc(sizeof(t_prompt))))
		return (NULL);
	prompt->line = line;
	return (prompt);
}

int		size_prompt(t_prompt *prompt)
{
	return (ft_strlen(prompt->line));
}

void	display_prompt(t_prompt *prompt)
{
	ft_putstr(prompt->line);
}
