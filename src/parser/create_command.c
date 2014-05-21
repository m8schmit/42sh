/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
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

t_command		*create_command(t_token *token_lst)
{
	t_command	*new;

	if (!(new = (t_command *)malloc(sizeof(*new))))
		return (NULL);
	new->token_lst = token_lst;
	new->first_job = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->first_job = make_job_lst(new->token_lst);
	return (new);
}
