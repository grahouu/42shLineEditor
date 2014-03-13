/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 22:01:06 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/14 00:04:43 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

/*
**	Keyboard entries values
*/
# define KEY_CTRL_A			1
# define KEY_CTRL_C			3
# define KEY_CTRL_D			4

# define KEY_TAB			9
# define KEY_ESC			27
# define KEY_BACKSPACE		127
# define KEY_RETURN			10
# define KEY_DEL			2117294875

# define KEY_UP				4283163
# define KEY_DOWN			4348699
# define KEY_LEFT			4479771
# define KEY_RIGHT			4414235

# define KEY_SHIFT_UP		16690
# define KEY_SHIFT_DOWN		16946
# define KEY_SHIFT_LEFT		17458
# define KEY_SHIFT_RIGHT	17202

# define KEY_PAGE_UP		2117425947
# define KEY_PAGE_DOWN		2117491483

# define KEY_F1				5263131
# define KEY_F2				5328667
# define KEY_F3				5394203
# define KEY_F4				5459739

# define KEY_F5				892427035
# define KEY_F6				925981467
# define KEY_F7				942758683
# define KEY_F8				959535899
# define KEY_F9				808606491
# define KEY_F10			825383707

# define KEY_END			4610843
# define KEY_HOME			4741915

/*
**	Shell return values
*/
# define CTRLD_VALUE		-20

/*
**	Lengths
*/
# define HARD_TAB_SIZE		4

int		check_keyboard(t_edited_line *line);
int		key_escape_event(t_edited_line *line);
int		key_backspace_event(t_edited_line *line);
int		key_left_event(t_edited_line *line);
int		key_right_event(t_edited_line *line);

#endif
