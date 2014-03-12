/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_static.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 23:33:44 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_STATIC_H
# define LINE_EDITOR_STATIC_H

# include <line_editor.h>
# include <termios.h>

void			action_add_letter(int letter, t_edited_line *line);
void			action_key_backspace(t_edited_line *line);
void			action_key_left(t_edited_line *line);
void			action_key_right(t_edited_line *line);
void			print_line(t_edited_line *line);
int				ft_outc(int c);

#endif
