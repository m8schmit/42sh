/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:25:57 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:25:57 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2)
	{
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			i++;
		}
		return (s1);
	}
	else
		return (0);
}
