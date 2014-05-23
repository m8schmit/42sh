/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:31 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:31 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void			command_lst_print(t_command *command_lst)
{
	t_command	*lst;
	t_token		*token;
	int			i;

	lst = command_lst;
	i = 1;
	while (lst != NULL)
	{
		ft_putstr("Command ");
		ft_putnbr(i++);
		ft_putstr(" : [");
		token = lst->token_lst;
		while (token != NULL)
		{
			ft_putstr(token->str);
			token = token->next;
		}
		ft_putstr("]\n");
		job_lst_print(lst->first_job);
		lst = lst->next;
	}
	ft_putstr("\n");
}
