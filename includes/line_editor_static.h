/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_static.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:58:49 by acollin           #+#    #+#             */
/*   Updated: 2014/03/13 22:27:25 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITOR_STATIC_H
# define LINE_EDITOR_STATIC_H

# include <line_editor.h>
# include <termios.h>

void			print_line(t_edited_line *line);
int				ft_outc(int c);

#endif
