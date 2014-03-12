/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42_check_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 10:43:52 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:50:50 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int				sh42_check_action(t_list *line, char *buf, t_info *info)
{
	if (is_esc_key(buf))
		return (-1);
	else if (is_enter_key(buf))
		return (-1);
	else if (is_up_key(buf))
		return (-1);
	else if (is_down_key(buf))
		return (-1);
	else if (is_left_key(buf))
		action_key_left(line, info);
	else if (is_right_key(buf))
		action_key_right(line, info);
	else if (is_space_key(buf))
		return (0);
	else if (is_backspace_key(buf))
		return (-1);
	else if (is_del_key(buf))
		return (-1);
	else
		action_add_letter(line, buf, info);
	return (0);
}
