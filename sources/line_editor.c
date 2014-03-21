/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:38:20 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/03/21 19:55:03 by acollin          ###   ########.fr       */
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

static t_edited_line	*init_edited_line(t_prompt *prompt)
{
	t_edited_line		*line;
	t_info				*info;

	line = ft_memalloc(sizeof(*line));
	info = ft_memalloc(sizeof(*info));
	line->data = ft_lst_new(NULL);
	line->len_prompt = size_prompt(prompt);
	line->win_nbchar = line->len_prompt;
	line->prompt = prompt;
	line->esc_key = 0;
	line->info = info;
	info->max_char = 0;
	info->min_char = 0;
	info->nb_char = 0;
	info->col = 0;
	info->row = 0;
	info->curr_pos = 0;
	info->curr_mod = 0;
	info->last_mod = 0;
	info->last_pos = 0;
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

int					line_editor(char **line, t_prompt *prompt)
{
	int				ret;
	t_edited_line	*edited_line;

	edited_line = init_edited_line(prompt);
	tputs(tgetstr("sc", NULL), 1, ft_outc);
	display_prompt(prompt);
	ret = 1;
	while (ret > 0)
	{
		ret = check_keyboard(edited_line);
		if (ret > 0)
		{
			debug("---------- AFTER ACTION ----------");
			debug("->CURRENT");
			debug_char(*((char *)edited_line->data->curr->content));
			debug("->CURRENT_CURSOR");
			if (edited_line->data->curr->next)
			{
				debug_char(*((char *)edited_line->data->curr->next->content));
			}
			else
				debug("(NULL)");
			debug("->WIN_NBCHAR");
			debug_int(edited_line->win_nbchar);
		}
	}
	*line = list_to_string(edited_line->data);
	return (ret);
}
