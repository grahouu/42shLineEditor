/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 15:56:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <termcap.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_info
{
	int			curs_pos;
	int			len_line;
	int			len_prompt;
	int			len_old_line;
}						t_info;

int				sh42_init_term(void);
void			sh42_default_term(void);
int				sh42_check_action(t_list *line, char *buf, t_info *info);
void			action_add_letter(t_list *line, char *buf, t_info *info);
void			action_key_backspace(t_list *line, t_info *info);
void			action_key_left(t_list *line, t_info *info);
void			action_key_right(t_list *line, t_info *info);
void			print_line(t_list *line, t_info *info);
void			set_oldterm(struct termios *new_term);
void			set_newterm(struct termios *new_term);
struct termios	*get_oldterm(void);
struct termios	*get_newterm(void);
int				ft_outc(int c);
int				is_esc_key(char *buffer);
int				is_enter_key(char *buffer);
int				is_space_key(char *buffer);
int				is_backspace_key(char *buffer);
int				is_del_key(char *buffer);
int				is_up_key(char *buffer);
int				is_down_key(char *buffer);
int				is_right_key(char *buffer);
int				is_left_key(char *buffer);
int				is_tab_key(char *buffer);
int				is_nextpage_key(char *buffer);
int				is_backpage_key(char *buffer);

#endif
