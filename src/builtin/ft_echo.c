/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:15 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:15 by apantiez         ###   ########.fr       */
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
