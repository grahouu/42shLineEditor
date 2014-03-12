/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:55:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 00:01:07 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor_static.h>
#include <keyboard.h>
#include <unistd.h>

#include <term.h>

int				check_keyboard(t_edited_line *line)
{
	int			key;

	key = 0;
	read(0, (char*)&key, 4);
	if (key == KEY_RETURN)
		return (0);
	if (key == KEY_CTRL_C)
		return (-1);
	if (key == KEY_CTRL_D && line->data->len)
	{
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		return (1);
	}
	action_add_letter(key, line);
	if (key == KEY_CTRL_D)
		return (0);
	return (1);
}
