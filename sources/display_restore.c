/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:31:07 by acollin           #+#    #+#             */
/*   Updated: 2014/03/13 01:59:54 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <stdlib.h>

void			line_editor_restore_display(struct termios *display_backup)
{
	if (tcsetattr(0, TCSANOW, display_backup) == -1)
		exit(-1);
	tputs(tgetstr("te", NULL), 1, ft_outc);
}
