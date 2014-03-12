/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_backspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:23:33 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 21:46:52 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <stdlib.h>

void			action_key_backspace(t_edited_line *line)
{
	if (line->curs_pos > 0)
	{
		ft_lst_del_atom(line->data, line->data->curr, &free);
		line->curs_pos--;
		line->len_old_line = line->len_line;
		line->len_line--;
	}
}
