/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42_init_term.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:18:52 by acollin           #+#    #+#             */
/*   Updated: 2014/03/11 19:02:24 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void			set_terminfo_db(void)
{
	char	*name_term;
	int		ret;

	if ((name_term = getenv("TERM")) == NULL)
		exit(0);
	if ((ret = tgetent(NULL, name_term) != 1))
		exit(0);
}

int			sh42_init_term(void)
{
	struct termios		*newterm;
	struct termios		*oldterm;

	newterm = (struct termios *) malloc(sizeof(*newterm));
	oldterm = (struct termios *) malloc(sizeof(*oldterm));
	set_terminfo_db();
	if (tcgetattr(0, oldterm) == -1)
		return (-1);
	set_oldterm(oldterm);
	if (tcgetattr(0, newterm) == -1)
		return (-1);
	newterm->c_lflag &= ~(ICANON | ECHO | ISIG);
	newterm->c_cc[VMIN] = 1;
	newterm->c_cc[VTIME] = 0;
	set_newterm(newterm);
	if (tcsetattr(0, TCSANOW, newterm) == -1)
		return (-1);
	tputs(tgetstr("im", NULL), 1 , ft_outc);
	return (0);
}
