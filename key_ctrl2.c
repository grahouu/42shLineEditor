/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ctrl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:38:23 by acollin           #+#    #+#             */
/*   Updated: 2014/02/12 16:18:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "libft.h"

int		is_tab_key(char *buffer)
{
	char	*key;

	key = tgetstr("kT", NULL);
	if (ft_memcmp(buffer, key, sizeof(char) * 3) == 0)
		return (1);
	return (0);
}

int		is_nextpage_key(char *buffer)
{
	char	*key;

	key = tgetstr("kN", NULL);
	if (ft_memcmp(buffer, key, sizeof(char) * 3) == 0)
		return (1);
	return (0);
}

int		is_backpage_key(char *buffer)
{
	char	*key;

	key = tgetstr("kP", NULL);
	if (ft_memcmp(buffer, key, sizeof(char) * 3) == 0)
		return (1);
	return (0);
}
