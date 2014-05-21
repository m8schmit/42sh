/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

void		token_free(t_token **token)
{
	t_token	*to_free;

	to_free = *token;
	ft_strdel(&(to_free->str));
	free(to_free);
	to_free = NULL;
}

void		token_lst_free(t_token **token_lst)
{
	t_token	*curr;
	t_token	*to_free;

	curr = *token_lst;
	while (curr != NULL)
	{
		to_free = curr;
		curr = curr->next;
		token_free(&to_free);
	}
	*token_lst = NULL;
}
