/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:19 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/27 14:46:59 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

unsigned int			count_word(char *s)
{
	unsigned int		words;

	words = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	words++;
	while (*s)
	{
		if (*s == ' ' || *s == '\t')
		{
			while (*s == ' ' || *s == '\t')
				s++;
			if (*s == '\"' || *s == '\'')
			{
				while (*s != '\'' && *s != '\"')
					s++;
			}
			words++;
		}
		if (*s)
			s++;
	}
	return (words);
}

static unsigned int		mystrlen(char *s)
{
	unsigned int		size;
	char				quote;

	size = 0;
	quote = 0;
	if (*s == '\'' || *s == '\"')
	{
		ft_printf("in \" or \'");
		quote = *s;
		while (*++s != quote)
		{
			ft_printf("not \"");
			size++;
		}
	}
	else
	{
		while (*s && *s++ != ' ')
			size++;
	}
	return (size);
}

static char				**mysplit(char *str)
{
	char				**ret;
	char				delim;
	unsigned int		i;
	unsigned int		k;

	i = 0;
	ft_printf("str in mysplit = %s\n, word count = %d\n", str, count_word(str));
	if (!str
			|| !(ret = (char **)malloc(sizeof(char *) * (count_word(str) + 1))))
		return (NULL);
	while (*str && !(k = 0))
	{
		delim = ' ';
		ft_printf("mystrlen = %d\n", mystrlen(str));
		if (!(ret[i] = (char *)malloc(sizeof(char) * (mystrlen(str) + 1))))
			return (NULL);
		if (*str == '\'' || *str == '\"')
			delim = *str++;
		while (*str && *str != delim)
			ret[i][k++] = *str++;
		if (delim != ' ')
			ret[i][k] = *str;
		str = (*str) ? (str + 1) : str;
		ret[i++][k] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}

t_process				*create_process(char *str)
{
	t_process			*new_process;

	if (!(new_process = (t_process *)malloc(sizeof(*new_process))))
		return (NULL);
	if (str)
		new_process->av = mysplit(str);
	else
		new_process->av = NULL;
	new_process->FD_IN = STDIN_FILENO;
	new_process->FD_OUT = STDOUT_FILENO;
	new_process->FD_ERR = STDERR_FILENO;
	new_process->next = NULL;
	new_process->prev = NULL;
	return (new_process);
}

