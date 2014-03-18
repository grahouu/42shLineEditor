/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/17 20:07:26 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

# include <stdio.h>
# include "prompt.h"
# include <libft.h>
# include <termios.h>

typedef struct		s_edited_line
{
	t_list			*data;
	int				curs_pos;
	int				len_line;
	int				len_prompt;
	int				len_old_line;
	int				old_atom;
	t_prompt		*prompt;
	int				esc_key;
}					t_edited_line;

FILE			*fd_debug(void);
void			debug_int(int a);
void			debug_char(char c);
void			debug(char *str);
void			debug_p(void *p);

int			line_editor(char **line, t_prompt *prompt);
int			line_editor_init_display(struct termios *display_backup);
void		line_editor_restore_display(struct termios *display_backup);

#endif
