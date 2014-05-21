/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s1);
	while (n-- && *s2 != '\0')
	{
		s1[i] = *(s2++);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
