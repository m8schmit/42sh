/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:21 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:21 by apantiez         ###   ########.fr       */
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
