/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:33 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:33 by apantiez         ###   ########.fr       */
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
