/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:38:20 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 17:51:39 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include <keyboard.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>

int					ft_outc(int c)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

static t_edited_line	*init_edited_line(t_option *option)
{
	t_edited_line		*line;
	t_info				*info;

	line = ft_memalloc(sizeof(*line));
	info = ft_memalloc(sizeof(*info));
	line->data = ft_lst_new(NULL);
	line->option = option;
	line->option->prompt->len = size_prompt(option->prompt);
	line->custom_bell = 0;
	line->esc_key = 0;
	line->info = info;
	info->max_char = 0;
	info->min_char = 0;
	info->nb_char = line->option->prompt->len;
	info->col = 0;
	info->row = 0;
	info->curr_pos = 0;
	info->curr_mod = 0;
	info->last_mod = 0;
	info->last_pos = 0;
	return (line);
}

static void			redim(int s)
{
	t_edited_line	*line;
	int				maxchar;

	(void)s;
	line = get_edited_line();
	get_win_size(line);
	tputs(tgetstr("cl", NULL), 1, ft_outc);
	print_line(line);
	line->data->curr = line->data->last;
	if (line->info->max_char >= line->info->len_line)
		line->info->nb_char = line->info->len_line;
	else
	{
		maxchar = line->info->max_char - line->info->col;
		line->info->nb_char = maxchar + line->info->last_mod;
	}
}

int					line_editor(char **line, t_option *option)
{
	int				ret;
	t_edited_line	*edited_line;
	struct termios	display_backup;

	line_editor_init_display(&display_backup);
	signal(SIGWINCH, &redim);
	edited_line = init_edited_line(option);
	set_edited_line(edited_line);
	display_prompt(option->prompt);
	ret = EDITED_GOON;
	while (ret > EDITED_STOP)
		ret = check_keyboard(edited_line);
	*line = list_to_string(edited_line->data);
	add_line_in_list(edited_line, *line);
	line_editor_restore_display(&display_backup);
	ft_putchar('\n');
	return (ret);
}
