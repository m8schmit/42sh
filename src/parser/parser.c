/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_command		*parser(char *str)
{
	t_token		*token_lst;
	t_command	*command_lst;

	command_lst = NULL;
	token_lst = get_token_lst(str);
	if (check_exp(token_lst))
		command_lst = make_command_lst(token_lst);
	token_lst_free(&token_lst);
	return (command_lst);
}
