/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:25:55 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:25:55 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = (*(str++) == '-' ? -sign : sign);
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + ((*(str++) - '0') * sign);
	return (nbr);
}
