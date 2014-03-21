/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 19:30:06 by acollin           #+#    #+#             */
/*   Updated: 2014/03/21 19:55:05 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor.h"
#include "line_editor_static.h"
#include <sys/ioctl.h>

void				get_win_size(t_edited_line *line)
{
	struct winsize	win;
	ioctl(0, TIOCGWINSZ, &win);
	line->info->col = win.ws_col;
	line->info->row = win.ws_row;
	calcul_info(line);
}

void				calcul_info(t_edited_line *line)
{
	line->info->curr_pos = ft_lst_curr_index(line->data) + line->len_prompt;
	line->info->curr_mod = line->info->curr_pos % line->info->col;
	line->info->last_pos = line->data->len + line->len_prompt;
	line->info->last_mod = line->info->last_pos % line->info->col;
	line->info->max_char = line->info->col * line->info->row;
	line->info->min_char = line->info->last_pos - line->info->nb_char;
}
