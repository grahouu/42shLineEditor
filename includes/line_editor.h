/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/21 19:51:29 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

# include <stdio.h>
# include "prompt.h"
# include <libft.h>
# include <termios.h>

typedef struct		s_info
{
	int				max_char;
	int				min_char;
	int				nb_char;
	int				col;
	int				row;
	int				curr_mod;
	int				curr_pos;
	int				last_mod;
	int				last_pos;
}					t_info;

typedef struct		s_edited_line
{
	t_list			*data;
	int				len_prompt;
	int				win_nbchar;
	t_prompt		*prompt;
	int				esc_key;
	t_info			*info;
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
