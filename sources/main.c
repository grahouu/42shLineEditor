/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:51:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/16 19:36:59 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include <line_editor.h>
#include <keyboard.h>
#include <libft.h>
#include <stdio.h>

int					main(void)
{
	int				ret;
	char			*edited_line;
	struct termios	display_backup;
	t_prompt		*prompt;

	prompt = prompt_new("42sh> ");
	line_editor_init_display(&display_backup);
	while (1)
	{
		ret = line_editor(&edited_line, prompt);
		if (ret == CTRLD_VALUE)
			break ;
		if (edited_line)
			printf("\n%s\n", edited_line);
	}
	line_editor_restore_display(&display_backup);
	return (0);
}
