/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 20:37:49 by jmancero          #+#    #+#             */
/*   Updated: 2014/03/27 20:37:49 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "struct.h"

void		ft_print_env(char **envp);
int			check_access(char *path);
char		*find_path_exec(char *exec, t_gen *envp);
char		*get_var_env(char *var, char **envp);
void		free_split(char ***to_free);
char		*check_and_get_path(char *var, t_gen *envp);

#endif
