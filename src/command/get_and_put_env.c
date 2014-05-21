/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_put_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:01:26 by apantiez          #+#    #+#             */
/*   Updated: 2014/03/27 21:01:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "exec.h"

void		ft_print_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putendl(envp[i]);
		i++;
	}
}

char		*get_var_env(char *var, char **envp)
{
	char	*find;
	int		i;

	i = 0;
	while (envp[i])
	{
		find = NULL;
		if ((ft_strncmp(envp[i], var, ft_strlen(var))) == 0)
		{
			find = ft_strstr(envp[i], var);
			break ;
		}
		i++;
	}
	return (find);
}
