/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_lst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:32 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:32 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_job				*job_lst_add(t_job *lst, t_token *token_lst, \
									char need_success)
{
	t_job			*new_job;
	t_job			*current;

	if (!(new_job = create_job(token_lst, need_success)))
		return (NULL);
	if (!lst)
		return (new_job);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_job;
	new_job->prev = current;
	return (lst);
}
