/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:17 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/27 15:43:22 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "command.h"

#define COM_SUCCESS 0
#define COM_NO_SUCCESS 256
#define COM_NO_FIND 65280

void		ft_command(t_command *com, t_gen *env)
{
	t_command	*tmp;
	t_job		*job;

	tmp = com;
	while (tmp != NULL)
	{
		job = tmp->first_job;
		while (job)
		{
			launch_job(job, env);
			if (env->status != 0 && job->need_success == NEED_SUCCESS)
				job = get_job_next(job, NEED_NO_SUCCESS);
			else if (env->status == 0 && job->need_success == NEED_SUCCESS)
				job = job->next;
			else if ((env->status != 0)
					&& job->need_success == NEED_NO_SUCCESS)
				job = job->next;
			else if (env->status == 0 && job->need_success == NEED_NO_SUCCESS)
				job = get_job_next(job, NEED_SUCCESS);
			else if (job->need_success == NO_CARE_SUCCESS)
				job = job->next;
		}
		tmp = tmp->next;
	}
}

t_job		*get_job_next(t_job *job, int success)
{
	t_job	*tmp;

	tmp = job;
	while (tmp != NULL)
	{
		if (tmp->need_success == success)
		{
			tmp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	return (tmp);
}
