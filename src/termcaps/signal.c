/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:36 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:36 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_sig_int(int x)
{
	t_gen	*gen;

	gen = recup_gen();
	if (gen->pid_fork > 0)
	{
		go_end(gen, NULL);
		ft_putchar('\n');
		ft_putstr(gen->ps1->aff);
		while (gen->hist->next)
			gen->hist = gen->hist->next;
		ft_bzero(gen->hist->buff, BUFF_SIZE);
		gen->hist->pose_buff = 0;
		gen->hist->len = 0;
		gen->hist->modif = 0;
		ft_bzero(gen->hist->value, BUFF_SIZE);
	}
	else
		kill(gen->pid_fork, x);
}

void	ft_sig_tstp(int x)
{
	t_gen	*gen;

	gen = recup_gen();
	if (gen->pid_fork > 0)
	{
		ft_putstr_fd(bell, gen->term->fd);
	}
	else
	{
		kill(gen->pid_fork, x);
	}
}

void	go_kill(t_gen *gen, char *buff)
{
	(void)buff;
	go_end(gen, NULL);
	destroy_gen();
	exit(0);
}
