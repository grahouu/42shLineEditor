/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/13 02:28:20 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

# include <libft.h>
# include <termios.h>

typedef struct		s_edited_line
{
	t_list			*data;
	int				curs_pos;
	int				len_line;
	int				len_prompt;
	int				len_old_line;
	int				pressed_escape;
}					t_edited_line;

int			line_editor(char **line, char *prompt);
int			line_editor_init_display(struct termios *display_backup);
void		line_editor_restore_display(struct termios *display_backup);

#endif
