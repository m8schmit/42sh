/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:22:11 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:22:11 by jmancero         ###   ########.fr       */
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
