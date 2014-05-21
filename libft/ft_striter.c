/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:26:00 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:26:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(s + i);
			i++;
		}
	}
}