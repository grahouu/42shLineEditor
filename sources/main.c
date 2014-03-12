/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:51:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/13 00:01:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor.h>
#include <keyboard.h>
#include <libft.h>
#include <stdio.h>

int					main(int argc, char **argv)
{
	char			*edited_line;
	struct termios	display_backup;
	char			*prompt;

	line_editor_init_display(&display_backup);
	if (argc > 1)
		prompt = argv[1];
	else
		prompt = ft_strdup("My Prompt>");
	while (1)
	{
		edited_line = line_editor(prompt);
		/*
		**	Change return value when CTRL-D
		*/
		if (edited_line && *edited_line == KEY_CTRL_D)
			break ;
		if (edited_line)
			printf("\n%s\n", edited_line);
	}
	line_editor_restore_display(&display_backup);
	return (0);
}
