/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:48 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

void			command_lst_free(t_command *command_lst)
{
	t_command	*curr;
	t_command	*to_free;

	curr = command_lst;
	while (curr)
	{
		to_free = curr;
		curr = curr->next;
		job_lst_free(to_free->first_job);
		to_free->first_job = NULL;
		token_lst_free(&(to_free->token_lst));
		to_free->background = 0;
		to_free->next = NULL;
		to_free->prev = NULL;
		free(to_free);
		to_free = NULL;
	}
	command_lst = NULL;
}
