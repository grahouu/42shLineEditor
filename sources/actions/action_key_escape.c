/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:18:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/13 23:21:10 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <term.h>
#include <stdlib.h>

void	disable_escape(t_edited_line *line)
{	
	if (line->esc_key)
	{
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		line->esc_key = 0;
	}
}

void	switch_escape(t_edited_line *line)
{	
	if (line->esc_key)
	{
		tputs(tgetstr("bl", NULL), 1, ft_outc);
		line->esc_key = 0;
	}
	else
		line->esc_key = 1;
}
