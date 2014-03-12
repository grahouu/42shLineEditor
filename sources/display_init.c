/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 21:13:12 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/12 21:37:41 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <stdlib.h>

static void				set_terminfo_db(void)
{
	char				*name_term;
	int					ret;

	if ((name_term = getenv("TERM")) == NULL)
		exit(0);
	if ((ret = tgetent(NULL, name_term) != 1))
		exit(0);
}

int						line_editor_init_display(struct termios *display_backup)
{
	struct termios		term;

	set_terminfo_db();
	if (tcgetattr(0, &term) == -1)
		return (-1);
	tcgetattr(0, display_backup);
	term.c_lflag &= ~(ICANON | ECHO | ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}
