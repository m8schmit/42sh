/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:01:26 by apantiez          #+#    #+#             */
/*   Updated: 2014/03/27 21:01:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "command.h"
#include "builtin.h"

int			ft_checkbuiltin(t_process *p, t_gen *gen)
{
	int		i;

	i = -1;
	if (!gen->builtin)
		gen->builtin = init_listbuiltin();
	while (gen->builtin[++i] && gen->builtin[i]->name)
		if (ft_strcmp(p->av[0], gen->builtin[i]->name) == 0)
			return (1);
	return (0);
}

int			ft_run_builtin(t_process *p, t_gen *env)
{
	ft_builtin(p, env);
	if (env->ret == 0)
		return (0);
	return (256);
}
