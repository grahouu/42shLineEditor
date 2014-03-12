/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42_defautl_term.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:31:07 by acollin           #+#    #+#             */
/*   Updated: 2014/02/18 14:58:45 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <term.h>
#include <stdlib.h>

void			sh42_default_term(void)
{
	struct termios	*oldterm;

	oldterm = get_oldterm();
	if (tcsetattr(0, TCSANOW, oldterm) == -1)
		exit(-1);
	tputs(tgetstr("te", NULL), 1, ft_outc);
}
