/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *s)
{
	const char	*str;

	if (s == NULL)
		return (0);
	str = s;
	while (*str)
		str++;
	return (str - s);
}
