/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:45:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/23 16:28:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>

void		ding_bell(t_edited_line *line)
{
	if (line->custom_bell)
	{
		if (fork() == 0)
			execlp("afplay", "afplay", "audio/bell.mp3", (char *)0);
	}
	else
		tputs(tgetstr("bl", NULL), 1, ft_outc);
}
