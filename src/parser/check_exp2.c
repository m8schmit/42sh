/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exp2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:30 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:30 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool			check_background(t_token *token_lst)
{
	if (token_lst->type == bg)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		return (TRUE);
	}
	return (parse_error(token_lst->str));
}

t_bool			check_logical(t_token *token_lst)
{
	if (token_lst->type == log_and \
			|| token_lst->type == log_or)
	{
		if (token_lst->next)
			return (check_exp(token_lst->next));
		else
			return (parse_error(token_lst->str));
	}
	return (parse_error(token_lst->str));
}
