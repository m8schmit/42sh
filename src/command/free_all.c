/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:28 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:28 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "exec.h"

void		free_split(char ***to_free)
{
	int		i;

	i = 0;
	while ((*to_free)[i] != NULL)
	{
		free((*to_free)[i]);
		(*to_free)[i] = NULL;
		i++;
	}
	free(*to_free);
	*to_free = NULL;
}
