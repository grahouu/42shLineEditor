/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:23:33 by acollin           #+#    #+#             */
/*   Updated: 2014/03/11 16:44:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void			action_key_backspace(t_list *line, t_info *info)
{
	if (info->curs_pos > 0)
	{
		ft_lst_del_atom(line, line->curr, &free);
		info->curs_pos--;
		info->len_old_line = info->len_line;
		info->len_line--;
	}
}
