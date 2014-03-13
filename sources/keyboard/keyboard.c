/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:55:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 02:21:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor_static.h>
#include <keyboard.h>
#include <unistd.h>
#include <term.h>

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

	key = 0;
	read(0, (char*)&key, 4);
	if (key == KEY_RETURN)
		return (0);
	if (key == KEY_CTRL_C)
		return (-1);
	if (key == KEY_CTRL_D)
		return (key_ctrl_d(line));
	if (key == KEY_ESC)
		return (action_key_esc(line));
	action_add_letter(key, line);
	return (1);
}
