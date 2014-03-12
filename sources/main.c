/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:51:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 21:47:01 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <line_editor.h>
#include <stdio.h>

int					main(int argc, char **argv)
{
	char			*edited_line;
	struct termios	display_backup;
	
	line_editor_init_display(&display_backup);
	if (argc > 1)
		edited_line = line_editor(argv[1]);
	else
		edited_line = line_editor("My Prompt> ");
	line_editor_restore_display(&display_backup);
	printf("\n\n%s\n", edited_line);
	return (0);
}
