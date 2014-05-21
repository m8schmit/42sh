/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:01:26 by apantiez          #+#    #+#             */
/*   Updated: 2014/03/27 21:30:03 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "exec.h"
#include "struct.h"
#include "error.h"
#include "command.h"

void		launch_process(t_process *p, t_gen *envp)
{
	check_redirection(p, envp);
	if ((envp->path = check_and_get_path(p->av[0], envp)) != NULL)
	{
		execve(envp->path, p->av, envp->env);
		exit(-1);
	}
	else
	{
		error(p, 0);
		exit(-1);
	}
}
