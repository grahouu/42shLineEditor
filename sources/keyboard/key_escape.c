/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 02:17:00 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 00:00:22 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor_static.h>
#include <actions.h>
#include <term.h>
#include <ncurses.h>

int				key_escape_event(t_edited_line *line)
{
	switch_escape(line);
	return (1);
}