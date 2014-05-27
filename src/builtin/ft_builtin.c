/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosdeve <abosdeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:15 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/27 22:10:18 by abosdeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "command.h"
#include "parser.h"
#include "error.h"

void	erase_list(t_builtin **list)
{
	t_builtin	**tmp;
	int			i;

	if (list)
	{
		tmp = list;
		i = 0;
		while (tmp[i] && tmp[i]->name)
		{
			free(tmp[i]->name);
			if (tmp[i]->name)
				free(tmp[i]->help);
			free(tmp[i]);
			i++;
		}
		free(tmp[i]);
		free(list);
	}
}

void	ft_builtin2(t_process *p, t_gen *env, int len)
{
	if (len == 2)
	{
		if (ft_strcmp(p->av[0], "cd") == 0)
			ft_cd(p->av[1], env);
		else if (ft_strcmp(p->av[0], "unsetenv") == 0)
			env = ft_unsetenv(p->av[1], env);
		else if (ft_strcmp(p->av[0], "pwd") == 0)
			env->ret = E2BIGA;
		else
			env->ret = ENOARG;
	}
	else if (len == 3)
	{
		if (ft_strcmp(p->av[0], "putenv") == 0)
			env = ft_putenv(p->av[1], p->av[2], env);
		else if (ft_strcmp(p->av[0], "setenv") == 0)
			env->ret = ENOARG;
		else
			env->ret = E2BIGA;
	}
	else if (len == 4 && ft_strcmp(p->av[0], "setenv") == 0)
		env = ft_setenv(p->av[1], p->av[2], ft_atoi(p->av[3]), env);
	else
		env->ret = E2BIGA;
}

void	ft_builtin(t_process *p, t_gen *env)
{
	int	len;

	env->ret = 0;
	len = ft_strstrlen(p->av);
	if (ft_strcmp(p->av[0], "env") == 0)
		ft_env(p, env);
	else if (ft_strcmp(p->av[0], "echo") == 0)
		ft_echo(p, env);
	else if (ft_strcmp(p->av[0], "help") == 0)
		ft_help(p, env->builtin);
	else if (ft_strcmp(p->av[0], "exit") == 0)
		ft_exit(p->av[1], env);
	else if (len == 1)
	{
		if (ft_strcmp(p->av[0], "pwd") == 0)
			ft_pwd(env, p);
		else if (ft_strcmp(p->av[0], "cd") == 0)
			ft_cd(p->av[1], env);
		else
			env->ret = ENOARG;
	}
	else
		ft_builtin2(p, env, len);
	if (env->ret == E2BIGA || env->ret == ENOARG)
		error(p, 0);
}
