/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:38:20 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/12 21:46:14 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>

int					ft_outc(int c)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

static t_edited_line	*init_edited_line(void)
{
	t_edited_line		*info;

	info = malloc(sizeof(*info));
	info->curs_pos = 0;
	info->len_line = 0;
	info->len_prompt = 11;
	info->len_old_line = 0;
	return (info);
}

static char			*list_to_string(t_list *line)
{
	char			*string;
	char			*current;
	char			letter;

	string = (char*)malloc((line->len + 1) * sizeof(char));
	if (string)
	{
		current = string;
		while ((letter = (char)ft_lst_next_content(line)))
		{
			*current = letter;
			current++;
		}
		*current = 0;
	}
	return (string);
}

char				*line_editor(char *prompt)
{
	char			buf[5] = {0};
	t_list			*line;
	t_edited_line		*info;

	info = init_edited_line();
	line = ft_lst_new(NULL);
	while (1)
	{
		ft_putstr(prompt);
		while (1)
		{
			ft_strclr(buf);
			read(0, buf, 4);
		}
	}
	return (list_to_string(line));
}
