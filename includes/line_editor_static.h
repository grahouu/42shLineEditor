/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_static.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 16:39:44 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_STATIC_H
# define LINE_EDITOR_STATIC_H

# include <line_editor.h>
# include <termios.h>

void			print_line(t_edited_line *line);
void			print_line_remove(t_edited_line *line);
void			calcul_info(t_edited_line *line);
void			set_edited_line(t_edited_line *new_line);
t_edited_line	*get_edited_line(void);
void			get_win_size(t_edited_line *line);
int				ft_outc(int c);
void			ding_bell(t_edited_line *line);
void			add_line_in_list(t_edited_line *line, char *newdata);
char			*list_to_string(t_list *line);

#endif
