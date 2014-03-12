/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 10:47:27 by acollin           #+#    #+#             */
/*   Updated: 2014/03/12 18:17:18 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void				print_line(t_list *line, t_info *info)
{
	char	*letter;
	t_atom	*tmp_curr;

	(void)info;
	tputs(tgetstr("cd", NULL), 1, ft_outc);
	tputs(tgetstr("sc", NULL), 1, ft_outc);
	tmp_curr = line->curr;
	ft_putstr(tmp_curr->content);
	while ((letter = ft_lst_next_content(line)))
		ft_putstr(letter);
	line->curr = tmp_curr;
	tputs(tgetstr("rc", NULL), 1, ft_outc);
}
