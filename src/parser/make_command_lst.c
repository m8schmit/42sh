/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:49 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:49 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_command			*make_command_lst(t_token *token_lst)
{
	t_command		*command_lst;
	t_token			*curr_tok;
	t_token			*com_token;
	char			exec;

	curr_tok = token_lst;
	command_lst = NULL;
	while (curr_tok != NULL)
	{
		exec = FOREGROUND;
		com_token = NULL;
		while (curr_tok && curr_tok->type != colon && curr_tok->type != bg)
		{
			com_token = token_add(curr_tok->str, curr_tok->type, com_token);
			curr_tok = curr_tok->next;
		}
		if (curr_tok)
		{
			if (curr_tok->type == bg)
				exec = BACKGROUND;
			curr_tok = curr_tok->next;
		}
		command_lst = command_lst_add(command_lst, com_token, exec);
	}
	return (command_lst);
}
