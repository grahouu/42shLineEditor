/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 12:10:58 by acollin           #+#    #+#             */
/*   Updated: 2014/03/17 13:39:55 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

typedef struct		s_prompt
{
	char		*line;
}					t_prompt;

t_prompt	*prompt_new(char *line);
int			size_prompt(t_prompt *prompt);
void		display_prompt(t_prompt *prompt);

#endif /* ! PROMPT_H */

