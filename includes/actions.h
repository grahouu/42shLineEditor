/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:56:54 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 02:34:09 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include <line_editor_static.h>

void	remove_previous_char(t_edited_line *line);
void	remove_previous_word(t_edited_line *line);
void	remove_next_char(t_edited_line *line);
void	remove_next_word(t_edited_line *line);
void	action_add_char(int letter, t_edited_line *line);
void	disable_escape(t_edited_line *line);
void	switch_escape(t_edited_line *line);

void	move_cursor_right(t_edited_line *line);
void	move_cursor_left(t_edited_line *line);
void	move_cursor_word_right(t_edited_line *line);
void	move_cursor_word_left(t_edited_line *line);

#endif
