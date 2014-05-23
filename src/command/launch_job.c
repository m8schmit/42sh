/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:17 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:17 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "libft.h"
#include "command.h"

void		launch_job(t_job *j, t_gen *envp)
{
	t_process	*p;
	int			mypipe[2];

	p = j->first_process;
	while (p)
	{
		if (p->next)
		{
			if (pipe(mypipe) < 0)
				ft_putstr("42sh : error pipe \n");
			p->FD_OUT = mypipe[1];
			p->next->FD_IN = mypipe[0];
		}
		ft_fork(p, envp);
		ft_close_pipe(p);
		p = p->next;
	}
}
