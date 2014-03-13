/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:17:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 02:22:22 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <ncurses.h>

int				action_key_esc(t_edited_line *line)
{
	if (line->pressed_escape)
	{
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		line->pressed_escape = 0;
	}
	else
		line->pressed_escape = 1;
	return (1);
}
