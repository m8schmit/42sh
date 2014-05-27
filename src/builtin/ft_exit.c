/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosdeve <abosdeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 19:55:50 by abosdeve          #+#    #+#             */
/*   Updated: 2014/05/27 22:17:31 by abosdeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"
#include "sh.h"

void	ft_exit(char *av, t_gen *env)
{
	if (av && !ft_isdigit(av[1]))
		env->ret = EAGNUM;
	ft_putstr("So long and Thanks for the fishes !\n");
	destroy_gen();
	//vérifier les leaks
	exit(EXIT_SUCCESS);
	//refaire le exit status
}