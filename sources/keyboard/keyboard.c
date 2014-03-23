/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:55:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/23 21:24:33 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor_static.h>
#include <keyboard.h>
#include <unistd.h>
#include <term.h>
#include <actions.h>
#include <stdio.h>

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

static int		check_escaped_keyboard(t_edited_line *line, int key)
{
	if (key == 'b' || key == 'B')
	{
		move_cursor_word_left(line);
		line->esc_key = 0;
		return (1);
	}
	if (key == 'f' || key == 'F')
	{
		move_cursor_word_right(line);
		line->esc_key = 0;
		return (1);
	}
	if (key == KEY_HOME)
	{
		line->custom_bell = 1 - line->custom_bell;
		line->esc_key = 0;
		return (1);
	}
	if (key == KEY_BACKSPACE)
		return (key_backspace_event(line));
	if (key == KEY_DELETE)
		return (key_delete_event(line));
	line->esc_key = 0;
	return (1);
}

int				check_keyboard(t_edited_line *line)
{
	int			key;

	key = 0;
	read(0, (char*)&key, 4);

	debug("KEYCODE : ");
	debug_int(key);

	get_win_size(line);
	calcul_info(line);
	if (key == KEY_ESC)
		return (key_escape_event(line));
	if (line->esc_key)
		return (check_escaped_keyboard(line, key));
	if (key == KEY_RIGHT)
		return (key_right_event(line));
	if (key == KEY_LEFT)
		return (key_left_event(line));
	if (key == KEY_UP)
		return (key_up_event(line));
	if (key == KEY_DOWN)
		return (key_down_event(line));
	if (key == KEY_RETURN)
		return (0);
	if (key == KEY_CTRL_C)
		return (ERR_EDITOR_CTRL_C);
	if (key == KEY_CTRL_D)
		return (key_ctrl_d(line));
	if (key == KEY_BACKSPACE)
		return (key_backspace_event(line));
	if (key == KEY_DELETE)
		return (key_delete_event(line));
	if ((unsigned int) key == KEY_TAB || ft_isprint(key))
		action_add_char(key, line);
	return (1);
}
