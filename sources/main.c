/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 14:51:21 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 16:42:47 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <fcntl.h>

int				ft_outc(int c)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

static t_info	*init_info(void)
{
	t_info			*info;

	info = malloc(sizeof(*info));
	info->curs_pos = 0;
	info->len_line = 0;
	info->len_prompt = 11;
	info->len_old_line = 0;
	return (info);
}

int				main(void)
{
	char			buf[5] = {0};
	t_list			*line;
	t_info			*info;

	sh42_init_term();
	info = init_info();
	line = ft_lst_new(NULL);
	while (1)
	{
		write(1, "Myprompt-> ", 11);
		while (1)
		{
			ft_strclr(buf);
			read(0, buf, 4);
			if (sh42_check_action(line, buf, info) == -1)
				break ;
/*			printf("curs_pos = %d\n", info->curs_pos);
			printf("len_line = %d\n", info->len_line);
			ft_putstr(line->curr->content);
			ft_putchar('\n');*/
		}
		if (sh42_check_action(line, buf, info) == -1)
			break ;
	}
	sh42_default_term();
	tputs(tgetstr("ei", NULL), 1, ft_outc);
	return (0);
}
