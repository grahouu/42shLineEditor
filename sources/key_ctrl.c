/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:29:28 by acollin           #+#    #+#             */
/*   Updated: 2014/02/12 16:15:29 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "libft.h"

int		is_esc_key(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0)
		return (1);
	return (0);
}

int		is_enter_key(char *buffer)
{
	if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
		return (1);
	return (0);
}

int		is_space_key(char *buffer)
{
	if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
		return (1);
	return (0);
}

int		is_backspace_key(char *buffer)
{
	if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
		return (1);
	return (0);
}

int		is_del_key(char *buffer)
{
	char	*key;

	key = tgetstr("kD", NULL);
	if (ft_memcmp(buffer, key, sizeof(char) * 3) == 0)
		return (1);
	return (0);
}
