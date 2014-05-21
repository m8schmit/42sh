/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s && !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
