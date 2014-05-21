/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:48 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:48 by jmancero         ###   ########.fr       */
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
