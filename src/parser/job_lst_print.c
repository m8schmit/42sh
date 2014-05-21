/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:49 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:49 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void			job_lst_print(t_job *job_lst)
{
	t_job		*curr;
	t_token		*token;
	int			i;

	curr = job_lst;
	i = 1;
	while (curr != NULL)
	{
		ft_putstr("Job ");
		ft_putnbr(i++);
		ft_putstr(" : [");
		token = curr->token_lst;
		while (token)
		{
			ft_putstr(token->str);
			token = token->next;
		}
		ft_putstr("]\n");
		process_lst_print(curr->first_process);
		curr = curr->next;
	}
}
