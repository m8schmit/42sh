/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:34 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:34 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_token			*token_lst_print(t_token *token_list)
{
	t_token		*ret;

	ret = token_list;
	if (token_list)
	{
		while (token_list)
		{
			ft_putstr("[");
			ft_putstr(token_list->str);
			ft_putstr("] [");
			ft_putnbr(token_list->type);
			ft_putstr("]");
			if (token_list->next)
				ft_putstr(" -> ");
			token_list = token_list->next;
		}
		ft_putchar('\n');
	}
	return (ret);
}
