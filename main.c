/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosdeve <abosdeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:06:21 by apantiez          #+#    #+#             */
/*   Updated: 2014/06/03 14:08:16 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"
#include "error.h"
#include "parser.h"
#include "builtin.h"
#include "command.h"

int				check_quote(char *tr);

void			ft_parse_and_exec(char *line, t_gen *gen)
{
	t_command	*command_lst;
	char		*tr;

	tr = ft_strtrim(line);
	command_lst = NULL;
	if (tr && tr[0])
	{
		if ((check_quote(tr)) == 1)
		{
			command_lst = parser(tr);
			ft_command(command_lst, gen);
			command_lst_free(command_lst);
		}
		else
			ft_dprintf(2, "42sh : %s\n", strror(EMQNOT));
	}
	if (tr != NULL)
		ft_strdel(&tr);
}

int				check_quote(char *tr)
{
	int			check;
	int			check_char;

	check = 0;
	check_char = 0;
	while (*tr)
	{
		if (*tr == '\'' || *tr == '\"')
		{
			check++;
		}
		else if (ft_isalnum(*tr))
			check_char++;
		tr++;
	}
	if ((check % 2) != 0 || check_char == 0)
		return (0);
	else
		return (1);
}

void			updat_prompt(t_ps1 *ps1)
{
	int			i;
	t_gen		*gen;

	gen = recup_gen();
	free(ps1->aff);
	ps1->aff = NULL;
	ps1->len = 0;
	parse_ps1(ps1);
	i = tgetnum("co");
	while (i--)
		ft_putstr_fd(tgetstr("kl", NULL), gen->term->fd);
}

void			prompt_next_line(t_gen *gen, char **line)
{
	char		buff[MAX_KEYCODE_LEN];
	int			ret;

	init_term();
	updat_prompt(gen->ps1);
	ft_putstr(gen->ps1->aff);
	if (gen->hist == NULL || gen->hist->buff[0] != 0)
		gen->hist = add_element(gen->hist);
	gen->term->wait = 1;
	while (gen->term->wait)
	{
		ft_bzero(buff, MAX_KEYCODE_LEN);
		ret = read(gen->term->fd, buff, MAX_KEYCODE_LEN);
		buff[ret] = 0;
		tc_stomp(buff, gen);
	}
	go_end(gen, NULL);
	gen->hist = save_hist(gen->hist);
	ft_putchar('\n');
	*line = gen->hist->buff;
	close_term();
}

void			ft_rappel(void)
{
	t_gen		*gen;
	char		*line;

	gen = recup_gen();
	while (1)
	{
		init_sig();
		gen->term->fd = open("/dev/tty", O_RDWR);
		if (check_env(gen) == NULL)
			ft_exit("20", gen);
		prompt_next_line(gen, &line);
		ft_parse_and_exec(line, gen);
		close(gen->term->fd);
	}
}

int				main(int ac, char **av, char **env)
{
	t_gen		*gen;

	(void)ac;
	(void)av;
	init_env(env);
	gen = recup_gen();
	gen->ps1->env = ft_strdup("[%1%*%0]-[%2%n%0]>");
	parse_ps1(gen->ps1);
	ft_rappel();
	ft_putnbr(gen->ps1->len);
	return (1);
}
