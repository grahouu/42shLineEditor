/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:41:43 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 15:32:08 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void			in_list(t_list *line)
{
	if (line->curr->prev)
		ft_lst_prev_content(line);
}

static void			in_display(t_info *info)
{
	if (info->curs_pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		info->curs_pos--;
	}
}

void			action_key_left(t_list *line, t_info *info)
{
	if (line->curr)
	{
		in_list(line);
		in_display(info);
	}
}
