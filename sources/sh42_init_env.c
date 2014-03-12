/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:59:30 by acollin           #+#    #+#             */
/*   Updated: 2014/02/18 14:48:52 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		sh42_init_env(void)
{
	extern char		**environ;
	char			**env;
	int				i;

	i = 0;
	while (environ[i])
		i++;
	if (!(env = (char **)(malloc(sizeof(char *) * (i + 1)))))
		return ;
	env[i] = '\0';
	while (i--)
		env[i] = ft_strdup(environ[i]);
}
