/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:21:50 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:21:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <unistd.h>

t_bool		parse_error(char *str)
{
	if (!write(STDOUT_FILENO, "Parse error near '", 18))
		return (FALSE);
	ft_putstr(str);
	if (!write(STDOUT_FILENO, "'.\n", 3))
		return (FALSE);
	return (FALSE);
}
