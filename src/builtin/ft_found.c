/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:15 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/26 16:59:43 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "builtin.h"
#include "exec.h"

int		ft_strstrlen(char **s)
{
	int	i;

	i = 0;
	if (s && *s)
	{
		while (s[i] != NULL)
			i++;
	}
	return (i);
}

int		ft_found(char *s, t_gen *env)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (env->env[i] != NULL && (ft_strncmp(s, env->env[i], len) != 0
				|| env->env[i][len] != '='))
		i++;
	if (ft_strncmp(s, env->env[i], len) == 0)
		return (i);
	return (0);
}

void	ft_freetmpenv(t_gen *tmpenv)
{
	int	j;

	j = 0;
	if (tmpenv)
	{
		if (tmpenv->env)
		{
			while (tmpenv->env[j])
				free(tmpenv->env[j++]);
			free(tmpenv->env);
		}
	}
	free(tmpenv);
	tmpenv = NULL;
}

int		verif_cd(t_gen *gen)
{
	int	i;

	i = 0;
	if (!get_var_env("HOME", gen->env))
		gen = ft_setenv("HOME", "/HOME", 0, gen);
	if (!get_var_env("PWD", gen->env))
	{
		gen = ft_setenv("PWD", "/", 0, gen);
		(ft_strcmp(gen->env[ft_found("PWD", gen)] + 4, "/"));
		i = chdir("/");
	}
	if (!get_var_env("OLDPWD", gen->env))
		gen = ft_setenv("OLDPWD", "/", 0, gen);
	return (i);
}
