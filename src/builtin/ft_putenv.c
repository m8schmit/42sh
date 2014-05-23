/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:28 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:28 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "struct.h"

t_gen			*ft_putenv(const char *n, const char *v, t_gen *env)
{
	return (ft_setenv(n, v, 1, env));
}
