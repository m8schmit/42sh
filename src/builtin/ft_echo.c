/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosdeve <abosdeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:15 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/27 22:17:36 by abosdeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"
#include "parser.h"

void	print_echo(char *str, int status)
{
	while (*str)
	{
		if (*str == '$')
		{
			str++;
			if (*str == '?')
			{
				str++;
				ft_printf("%d", WEXITSTATUS(status));
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
}

void	ft_echo(t_process *p, t_gen *env)
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
				print_echo(p->av[i], env->status);
				ft_putchar(' ');
				i++;
			}
		if (p->av[i])
			print_echo(p->av[i], env->status);
		if (n == 0)
			write(p->FD_OUT, "\n", 1);
	}
}
