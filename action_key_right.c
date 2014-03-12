/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:11:06 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:04:14 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void			in_list(t_list *line, t_info *info)
{
	if (info->curs_pos > 1 && line->curr->next)
		ft_lst_next_content(line);
}

static void			in_display(t_info *info)
{
	if (info->curs_pos < info->len_line)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		info->curs_pos++;
	}
}

void				action_key_right(t_list *line, t_info *info)
{
	if (line->curr)
	{
		in_list(line, info);
		in_display(info);
	}
}
