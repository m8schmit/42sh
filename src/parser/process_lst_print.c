/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:50 by jmancero         ###   ########.fr       */
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
