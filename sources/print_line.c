/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 10:47:27 by acollin           #+#    #+#             */
/*   Updated: 2014/03/23 11:18:21 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "line_editor_static.h"
#include <term.h>
#include <ncurses.h>
#include <unistd.h>
#include "actions.h"
#include <sys/ioctl.h>

void				print_line_remove(t_edited_line *line)
{
	char			*letter;
	t_atom			*tmp_curr;

	tputs(tgetstr("cd", NULL), 1, ft_outc);
	tputs(tgetstr("sc", NULL), 1, ft_outc);
	tmp_curr = line->data->curr;
	while ((letter = ft_lst_next_content(line->data)))
		ft_putchar(*letter);
	line->data->curr = tmp_curr;
	tputs(tgetstr("rc", NULL), 1, ft_outc);
}

void				print_line(t_edited_line *line)
{
	char			*letter;
	t_atom			*tmp_curr;

	display_prompt(line->option->prompt);
	tmp_curr = line->data->curr;
	line->data->curr = NULL;
	while ((letter = ft_lst_next_content(line->data)))
		ft_putchar(*letter);
	ft_lst_prev_content(line->data);
	calcul_info(line);
	line->data->curr = tmp_curr;
	if (!line->info->curr_mod && tmp_curr == line->data->last)
	{
		tputs(tgetstr("do", NULL), 1, ft_outc);
		tputs(tgetstr("cr", NULL), 1, ft_outc);
	}
}
