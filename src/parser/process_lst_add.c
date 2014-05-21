/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lst_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:50 by jmancero         ###   ########.fr       */
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
