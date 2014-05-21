/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:51 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:51 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <fcntl.h>

t_process		*update_fd(t_token *token, t_process **current)
{
	int			fd;

	fd = 0;
	if (token->type == append)
	{
		fd = open(token->next->str, O_APPEND | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_OUT = fd;
	}
	else if (token->type == redir_out)
	{
		fd = open(token->next->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_OUT = fd;
	}
	else if (token->type == redir_in)
	{
		fd = open(token->next->str, O_RDONLY);
		(*current)->FD_IN = fd;
	}
	else if (token->type == redir_err)
	{
		fd = open(token->next->str, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		(*current)->FD_ERR = fd;
	}
	return (*current);
}
