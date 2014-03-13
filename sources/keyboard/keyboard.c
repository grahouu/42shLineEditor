/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:55:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 00:02:46 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor_static.h>
#include <keyboard.h>
#include <unistd.h>
#include <term.h>
#include <actions.h>

static int		key_ctrl_d(t_edited_line *line)
{
	if (line->data->len)
	{	
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		return (1);
	}
	else
		return (CTRLD_VALUE);
}

int				check_keyboard(t_edited_line *line)
{
	int			key;

	/*
	**	Go to other function if escape pressed
	*/

	key = 0;
	read(0, (char*)&key, 4);
	if (key == KEY_RETURN)
		return (0);
	else if (key == KEY_CTRL_C)
		return (-1);
	else if (key == KEY_CTRL_D)
		return (key_ctrl_d(line));
	else if (key == KEY_ESC)
		return (key_escape_event(line));
	else if (key == KEY_BACKSPACE)
		return (key_backspace_event(line));
	else if (key == KEY_RIGHT)
		return (key_right_event(line));
	else if (key == KEY_LEFT)
		return (key_left_event(line));
	action_add_char(key, line);
	return (1);
}
