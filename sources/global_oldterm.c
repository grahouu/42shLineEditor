/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_oldterm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:48:27 by acollin           #+#    #+#             */
/*   Updated: 2014/02/18 14:46:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <term.h>
#include <unistd.h>

static struct termios	*global_oldterm(struct termios *new_term)
{
	static struct termios	*term;

	if (new_term != NULL)
		term = new_term;
	return (term);
}

void					set_oldterm(struct termios *new_term)
{
	global_oldterm(new_term);
}

struct termios		*get_oldterm(void)
{
	return (global_oldterm(NULL));
}
