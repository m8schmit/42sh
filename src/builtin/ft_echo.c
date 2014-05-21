/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:22:52 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:22:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"
#include "parser.h"

void	ft_echo(t_process *p)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (p->av[i] != NULL)
	{
		if (!ft_strcmp(p->av[i], "-n"))
			n = i++;
		if (p->av[i + 1] != NULL)
			while (p->av[i] && p->av[i + 1])
			{
				ft_dprintf(p->FD_OUT, "%s ", p->av[i]);
				i++;
			}
		if (p->av[i])
			ft_dprintf(p->FD_OUT, "%s", p->av[i]);
		if (n == 0)
			write(p->FD_OUT, "\n", 1);
	}
}
