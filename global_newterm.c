/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_newterm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:48:27 by acollin           #+#    #+#             */
/*   Updated: 2014/02/18 15:13:43 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <unistd.h>

static struct termios	*global_newterm(struct termios *new_term)
{
	static struct termios	*term;

	if (new_term != NULL)
		term = new_term;
	return (term);
}

void					set_newterm(struct termios *new_term)
{
	global_newterm(new_term);
}

struct termios		*get_newterm(void)
{
	return (global_newterm(NULL));
}
