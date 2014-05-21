/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lst_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:48 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_command		*command_lst_add(t_command *command_lst, t_token *token, \
										char background)
{
	t_command	*curr;
	t_command	*new;

	if (!(new = create_command(token)))
		return (NULL);
	new->background = background;
	if (!command_lst)
		return (new);
	curr = command_lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
	return (command_lst);
}
