/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschmit <mschmit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 14:04:31 by mschmit           #+#    #+#             */
/*   Updated: 2014/06/03 16:16:13 by mschmit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "sh.h"

void	ft_print_hist(void)
{
	int		i;
	t_gen	*gen;
	t_hist	*hist;

	i = 0;
	if ((gen = recup_gen()) != NULL)
	{
		hist = gen->hist;
		while(hist->prev != NULL)
			hist = hist->prev;
		while (hist != NULL)
		{
		ft_printf("%d %s\n", i, hist->value);
			hist = hist->next;
			i++;
		}
	}
}
