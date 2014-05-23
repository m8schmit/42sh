/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:22 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:22 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void print_key(char *key)
{
	ft_putstr("touche appuyer : [");
	ft_putnbr((int)key[0]);
	ft_putstr("] [");
	ft_putnbr((int)key[1]);
	ft_putstr("] [");
	ft_putnbr((int)key[2]);
	ft_putstr("] [");
	ft_putnbr((int)key[3]);
	ft_putstr("];\n");
}
