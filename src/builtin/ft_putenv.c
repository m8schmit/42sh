/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:22:52 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:22:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "struct.h"

t_gen			*ft_putenv(const char *n, const char *v, t_gen *env)
{
	return (ft_setenv(n, v, 1, env));
}
