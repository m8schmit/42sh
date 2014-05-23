/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:21 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:21 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

void			process_lst_print(t_process *process)
{
	ft_putstr("process : ");
	while (process)
	{
		ft_putstr(" [");
		ft_putstr(process->av[0]);
		ft_putstr(" IN : ");
		ft_putnbr(process->FD_IN);
		ft_putstr(" OUT : ");
		ft_putnbr(process->FD_OUT);
		ft_putstr(" ERR : ");
		ft_putnbr(process->FD_ERR);
		ft_putstr("] ");
		if (process->next)
			ft_putstr("->");
		process = process->next;
	}
	ft_putchar('\n');
}
