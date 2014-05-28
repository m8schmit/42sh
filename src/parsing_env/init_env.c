/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:22 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/28 15:02:00 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtin.h"
#include "exec.h"

void				free_gen(void)
{
	t_gen			*gen;

	gen = recup_gen();
	free(gen);
	gen = NULL;
}

t_gen				*recup_gen(void)
{
	static t_gen	*gen = NULL;

	if (gen == NULL)
	{
		gen = (t_gen *)malloc(sizeof(t_gen));
		gen->ps1 = (t_ps1 *)malloc(sizeof(t_ps1));
		gen->term = (t_term *)malloc(sizeof(t_term));
		gen->term->key = NULL;
		gen->hist = NULL;
		gen->ps1->aff = NULL;
		gen->ps1->env = NULL;
		gen->ps1->len = 0;
		gen->path = NULL;
		gen->ret = 0;
		gen->builtin = NULL;
		gen->env = NULL;
		gen->env_orig = NULL;
		gen->pid_fork = 1;
	}
	return (gen);
}

char				*ft_getenv(char *to_search)
{
	t_gen			*gen;
	int				i;

	gen = recup_gen();
	i = 0;
	if (gen->env)
	{
		while (gen->env[i])
		{
			if (!ft_strncmp(gen->env[i], to_search, ft_strlen(to_search)))
				break ;
			i++;
		}
		if (!gen->env[i])
			return (NULL);
	}
	else
		return (NULL);
	return (gen->env[i] + ft_strlen(to_search));
}

void				init_env(char **env)
{
	t_gen			*gen;
	int				i;

	i = 0;
	gen = recup_gen();
	if (!env || env[0] == NULL)
	{
		gen->env = (char **)malloc(sizeof(char *) * 5);
		check_env(gen);
		while (i < 5)
			gen->env[i++] = NULL;
		ft_putstr_fd("The environment to lack of information, 42sh will add.\n",
							2);
		return ;
	}
	else
		gen->env_orig = env;
	while (gen->env_orig[i])
		i++;
	gen->env = (char **)malloc(sizeof(char *) * (i + 1));
	gen->env[i] = NULL;
	while (--i >= 0)
		gen->env[i] = ft_strdup(gen->env_orig[i]);
}

t_gen				*check_env(t_gen *gen)
{
	int				chdir_return;

	if (!get_var_env("PATH", gen->env))
		gen = ft_setenv("PATH",
				"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin",
				0, gen);
	if (!get_var_env("HOME", gen->env))
		gen = ft_setenv("HOME", "/home", 0, gen);
	if (!get_var_env("PWD", gen->env))
	{
		gen = ft_setenv("PWD", "/", 0, gen);
		(ft_strcmp(gen->env[ft_found("PWD", gen)] + 4, "/"));
		if ((chdir_return = chdir("/")) == -1)
			return (NULL);
	}
	if (!get_var_env("OLDPWD", gen->env))
		gen = ft_setenv("OLDPWD", "/", 0, gen);
	if (!get_var_env("USER", gen->env))
		gen = ft_setenv("USER", "Anonymous", 0, gen);
	return (gen);
}
