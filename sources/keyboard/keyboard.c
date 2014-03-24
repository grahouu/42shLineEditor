/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:55:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 19:53:55 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "keyboard.h"
#include "actions.h"
#include <unistd.h>
#include <term.h>

static int		key_ctrl_d(t_edited_line *line)
{
	if (line->data->len)
	{
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		return (EDITED_GOON);
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
	int			ret;

	key = 0;
	if ((ret = read(0, (char*)&key, 4)) == -1)
		return (ret);
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
	if (key == KEY_UP && line->option->mode == NORMAL_MODE)
		return (key_up_event(line));
	if (key == KEY_DOWN && line->option->mode == NORMAL_MODE)
		return (key_down_event(line));
	if (key == KEY_RETURN)
		return (EDITED_STOP);
	if (key == KEY_CTRL_C && line->option->mode == NORMAL_MODE)
		return (ERR_EDITOR_CTRL_C);
	if (key == KEY_CTRL_D)
		return (key_ctrl_d(line));
	if (key == KEY_BACKSPACE)
		return (key_backspace_event(line));
	if (key == KEY_DELETE)
		return (key_delete_event(line));
	if ((unsigned int) key == KEY_TAB || ft_isprint(key))
		action_add_char(key, line);
	return (EDITED_GOON);
}
