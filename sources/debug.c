/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 13:01:31 by acollin           #+#    #+#             */
/*   Updated: 2014/03/19 09:08:15 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define FILE_DEBUG "/dev/ttys002"

FILE				*fd_debug(void)
{
	static FILE		*file = NULL;

	if (!file)
		file = fopen(FILE_DEBUG, "w");
	return (file);
}

void				debug(char *str)
{
	fprintf(fd_debug(), "%s\n", str);
}

void				debug_char(char c)
{
	fprintf(fd_debug(), "%c\n", c);
}

void				debug_p(void *p)
{
	fprintf(fd_debug(), "%p\n", p);
}

void				debug_int(int a)
{
	fprintf(fd_debug(), "%d\n", a);
}
