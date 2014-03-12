/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:38:20 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/12 23:53:03 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor.h>
#include <keyboard.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>

#include <stdio.h>

int					ft_outc(int c)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

static t_edited_line	*init_edited_line()
{
	t_edited_line		*line;

	line = malloc(sizeof(*line));
	line->curs_pos = 0;
	line->len_line = 0;
	line->len_prompt = 11;
	line->len_old_line = 0;
	line->data = ft_lst_new(NULL);
	return (line);
}

static char			*list_to_string(t_list *line)
{
	char			*string;
	char			*current;
	char			*letter;

	string = (char*)malloc((line->len + 1) * sizeof(char));
	if (string)
	{
		current = string;
		line->curr = NULL;
		while ((letter = (char*)ft_lst_next_content(line)))
		{
			*current = *letter;
			current++;
		}
		*current = 0;
	}
	return (string);
}

char				*line_editor(char *prompt)
{
	int				ret;
	t_edited_line	*line;

	line = init_edited_line();
	ret = 1;
	ft_putstr(prompt);
	while ((ret = check_keyboard(line)) > 0);
	if (ret < 0)
		return (NULL);
	return (list_to_string(line->data));
}
