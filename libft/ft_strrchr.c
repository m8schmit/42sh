/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:01 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:01 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		save;

	i = 0;
	save = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			save = i;
		}
		i++;
	}
	if (c == 0)
	{
		return ((char *)&s[i]);
	}
	else if (save == -1)
	{
		return (NULL);
	}
	return ((char *)&s[save]);
}
