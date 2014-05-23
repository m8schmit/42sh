/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_lst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:32 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:32 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

void			job_lst_free(t_job *job_lst)
{
	t_job	*curr;
	t_job	*to_free;

	curr = job_lst;
	while (curr)
	{
		to_free = curr;
		curr = curr->next;
		process_lst_free(to_free->first_process);
		to_free->first_process = NULL;
		token_lst_free(&(to_free->token_lst));
		to_free->need_success = 0;
		to_free->next = NULL;
		to_free->prev = NULL;
		free(to_free);
		to_free = NULL;
	}
	job_lst = NULL;
}
