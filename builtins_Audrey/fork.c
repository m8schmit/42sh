/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 20:26:59 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/23 20:29:32 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*condition_1_call_fork(int i, char **foo, t_list *list)
{
	if (!ft_strcmp(foo[0], "env") && ft_strcmp(foo[1], "-i"))
	{
		if (i != 1)
			ft_printf("Wrong number of arguments.\n");
		else
			ft_env(list);
		return (list);
	}
	else if (ft_strcmp(foo[0], "setenv") == 0)
	{
		if (i != 3)
			ft_printf("Wrong number of arguments.\n");
		if (!ft_strcmp(foo[1], "PATH") || !ft_strcmp(foo[1], "HOME"))
			ft_printf("Cannot change this key.\n");
		else
			ft_setenv(list, foo[1], foo[2]);
		return (list);
	}
	return (list);
}

void		ft_fork(int i, t_list *list, char **foo)
{
	foo[0] = is_path(foo[0], list);
	i = fork();
	if (i == 0)
	{
		if (ft_strcmp(foo[0], "env") && ft_strcmp(foo[1], "-i"))
			execve(foo[0], foo, NULL);
		else
			execve(foo[0], foo, ft_list_to_tab(list));
		exit(0);
	}
	else if (i > 0)
	{
		wait(NULL);
		ft_freesplit(foo);
	}
	else
		ft_putstr("fork failed.");
}

t_list		*call_fork(char *buf, t_list *list)
{
	pid_t	i;
	char	**foo;

	buf = ft_change_char(buf, '\t', ' ');
	foo = ft_strsplit(buf, ' ');
	i = 0;
	while (foo[i])
		i++;
	if (ft_strcmp(foo[0], "cd") == 0)
		ft_cd(i, list, foo);
	else if (ft_strcmp(foo[0], "env") == 0)
		condition_1_call_fork(i, foo, list);
	else if (ft_strcmp(foo[0], "setenv") == 0)
		ft_ft_setenv(list, foo);
	else if (ft_strcmp(foo[0], "unsetenv") == 0)
		ft_ft_unsetenv(i, list, foo);
	else
		ft_fork(i, list, foo);
	return (list);
