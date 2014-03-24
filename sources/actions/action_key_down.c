/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 15:34:09 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 19:51:19 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include "actions.h"
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

static void			reposition_begin(t_edited_line *line)
{
	int				curr_nbline;

	curr_nbline = (line->info->curr_pos - 1) / line->info->col;
	tputs(tgetstr("cr", NULL), 1, ft_outc);
	while (curr_nbline--)
		tputs(tgetstr("up", NULL), 1, ft_outc);
}

static void			convert_str_to_list(t_edited_line *line, char *old_line)
{
	ft_lst_del(line->data, &free);
	line->data = ft_lst_new(NULL);
	line->info->nb_char = size_prompt(line->option->prompt);
	while (*old_line)
	{
		action_add_char((int)*old_line, line);
		old_line++;
	}
}

void				action_key_down(t_edited_line *line)
{
	if (!line->option->historic->len
	|| (line->option->historic->curr && !line->option->historic->curr->next))
	{
		ding_bell(line);
		return ;
	}
	else
		ft_lst_next_content(line->option->historic);
	reposition_begin(line);
	convert_str_to_list(line, line->option->historic->curr->content);
}
