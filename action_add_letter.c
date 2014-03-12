/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:10:41 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:16:07 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void				action_add_letter(t_list *line, char *buf, t_info *info)
{
	if (info->curs_pos == 0)
	{
		ft_lst_push(line, ft_memdup(buf, sizeof(char)));
		if (line->curr && line->curr->prev)
			ft_lst_prev_content(line);
		else
			ft_lst_next_content(line);
	}
	else
	{
		ft_lst_push_after_curr(line, ft_memdup(buf, sizeof(char)));
		ft_lst_next_content(line);
	}
	info->curs_pos++;
	info->len_old_line = info->len_line;
	info->len_line++;
	print_line(line, info);
	tputs(tgetstr("nd", NULL), 1, ft_outc);
}
