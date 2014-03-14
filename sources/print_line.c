/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 10:47:27 by acollin           #+#    #+#             */
/*   Updated: 2014/03/14 15:07:03 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <line_editor_static.h>
#include <term.h>
#include <ncurses.h>

void				print_line(t_edited_line *line)
{
	char			*letter;
	t_atom			*tmp_curr;

	tputs(tgetstr("cd", NULL), 1, ft_outc);
	tputs(tgetstr("sc", NULL), 1, ft_outc);
	tmp_curr = line->data->curr;
	ft_putchar(*((char *)tmp_curr->content));
	while ((letter = ft_lst_next_content(line->data)))
		ft_putchar(*letter);
	line->data->curr = tmp_curr;
	tputs(tgetstr("rc", NULL), 1, ft_outc);
}
