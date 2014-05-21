/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned i, char))
{
	int		i;
	char	*str;

	i = 0;
	if (s && f)
	{
		str = ft_memalloc(ft_strlen((char *)s) + 1);
		if (str)
		{
			while (s[i] != '\0')
			{
				str[i] = f(i, s[i]);
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
