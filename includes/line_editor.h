/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 17:51:49 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_H
# define LINE_EDITOR_H

#include <stdio.h>
# include "prompt.h"
# include "libft.h"
# include <termios.h>

# define ERR_EDITOR_CTRL_C -21
# define NORMAL_MODE 5
# define NOFINISH_MODE 6
# define EDITED_STOP 1
# define EDITED_GOON 2

typedef struct		s_info
{
	int				max_char;
	int				min_char;
	int				nb_char;
	int				len_line;
	int				col;
	int				row;
	int				curr_mod;
	int				curr_pos;
	int				last_mod;
	int				last_pos;
}					t_info;

typedef struct		s_option
{
	t_list			*historic;
	t_prompt		*prompt;
	int				mode;
}					t_option;

typedef struct		s_edited_line
{
	t_list			*data;
	int				custom_bell;
	int				esc_key;
	t_info			*info;
	t_option		*option;
}					t_edited_line;

FILE			*fd_debug(void);
void			debug_int(int a);
void			debug_char(char c);
void			debug(char *str);
void			debug_p(void *p);

int			line_editor(char **line, t_option *option);
int			line_editor_init_display(struct termios *display_backup);
int			line_editor_init_display_start(struct termios *display_backup);
void		line_editor_restore_display(struct termios *display_backup);
void		line_editor_restore_display_end(struct termios *display_backup);

#endif
