/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:30:31 by acollin           #+#    #+#             */
/*   Updated: 2014/03/10 13:41:41 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termcap.h>

int		is_up_key(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		return (1);
	return (0);
}

int		is_down_key(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		return (1);
	return (0);
}

int		is_left_key(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		return (1);
	return (0);
}

int		is_right_key(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		return (1);
	return (0);
}
