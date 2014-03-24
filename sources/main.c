/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:51:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/24 17:51:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "line_editor.h"
#include "keyboard.h"
#include <stdlib.h>

int					main(void)
{
	int				ret;
	char			*edited_line;
	t_option		*option;
	struct termios	display_backup;

	line_editor_init_display_start(&display_backup);
	option = malloc(sizeof(t_option));
	option->historic = ft_lst_new(NULL);
	option->prompt = prompt_new("42sh> ");
	option->mode = NORMAL_MODE;
	while (1)
	{
		ret = line_editor(&edited_line, option);
		if (ret == CTRLD_VALUE)
			break ;
		if (ret == ERR_EDITOR_CTRL_C)
		{
			printf("ERROR_CRTL_C\n");
			break;
		}
	}
	line_editor_restore_display_end(&display_backup);
	return (0);
}
