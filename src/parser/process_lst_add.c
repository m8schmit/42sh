/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:21 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:21 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_process				*process_lst_add(t_process *lst, char *str)
{
	t_process			*new_process;
	t_process			*current;

	if (!(new_process = create_process(str)))
		return (NULL);
	if (!lst)
		return (new_process);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_process;
	new_process->prev = current;
	return (lst);
}
