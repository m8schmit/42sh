/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   know_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:01:26 by apantiez          #+#    #+#             */
/*   Updated: 2014/03/27 21:01:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft.h"
#include "error.h"

int				check_access(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) != -1)
		if (S_ISDIR(buf.st_mode) == 1)
			return (EDIRIS);
	if (access(path, F_OK) == -1)
		return (ENENTR);
	if (access(path, X_OK) == -1)
		return (ENPERM);
	return (0);
}
