/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:47:36 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 15:47:36 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	gen_tc_move_right(t_gen *gen, int i)
{
	int	tmp;

	tmp = gen->hist->pose_buff;
	while (i--)
	{
		tc_move_right(gen, 1, 0);
		gen->hist->pose_buff++;
	}
	gen->hist->pose_buff = tmp;
}

void	tc_del_char(t_gen *gen, int i)
{
	int	tmp;

	tmp = gen->hist->pose_buff;
	while (i--)
	{
		gen->hist->pose_buff--;
		gen_tc_move_left(gen, 1);
		ft_putstr_fd(tgetstr("dc", NULL), gen->term->fd);
	}
	gen->hist->pose_buff = tmp;
}

void	tc_clean_line(t_gen *gen)
{
	int	tmp;

	tmp = gen->hist->pose_buff;
	go_end(gen, NULL);
	gen->hist->pose_buff = gen->hist->len;
	while (gen->hist->pose_buff--)
	{
		if (ft_isnl(gen, gen->hist->pose_buff))
			ft_putstr_fd(tgetstr("ku", NULL), gen->term->fd);
		ft_putstr_fd(tgetstr("dl", NULL), gen->term->fd);
	}
	gen->hist->pose_buff = tmp;
	tmp = tgetnum("co");
	while (tmp--)
		ft_putstr_fd(tgetstr("kl", NULL), gen->term->fd);
	ft_putstr(gen->ps1->aff);
}

void	go_end(t_gen *gen, char *key)
{
	if (gen->hist->pose_buff != gen->hist->len)
	{
		(void)key;
		gen_tc_move_right(gen, gen->hist->len - gen->hist->pose_buff);
		gen->hist->pose_buff = gen->hist->len;
	}
}

void	go_start(t_gen *gen, char *key)
{
	if (gen->hist->pose_buff > 0)
	{
		(void)key;
		gen_tc_move_left(gen, gen->hist->pose_buff);
		gen->hist->pose_buff = 0;
	}
}
