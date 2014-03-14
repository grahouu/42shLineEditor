/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:51:11 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 01:47:25 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
#include <term.h>
#include <ncurses.h>

int			key_left_event(t_edited_line *line)
{
	move_cursor_left(line);
	return (1);
}
