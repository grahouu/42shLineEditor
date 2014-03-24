/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 23:18:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/24 18:02:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editor_static.h"
#include <term.h>
#include <stdlib.h>

void	disable_escape(t_edited_line *line)
{
	if (line->esc_key)
	{
		ding_bell(line);
		line->esc_key = 0;
	}
}

void	switch_escape(t_edited_line *line)
{
	if (line->esc_key)
	{
		ding_bell(line);
		line->esc_key = 0;
	}
	else
		line->esc_key = 1;
}
