/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:18:34 by oexall            #+#    #+#             */
/*   Updated: 2016/06/11 08:41:56 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(char *path)
{
	DIR	*dir;

	if ((dir = opendir(path)) != NULL)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

char	*ft_new_path(char *original, char *dir)
{
	char	*new_path;

	new_path = ft_strjoin(original, "/");
	new_path = ft_strjoin(new_path, dir);
	return (new_path);
}
