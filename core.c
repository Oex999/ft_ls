/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:34:12 by oexall            #+#    #+#             */
/*   Updated: 2016/06/06 16:20:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_new_path(char *original, char *dir)
{
	char	*new_path;

	new_path = ft_strjoin(original, "/");
	new_path = ft_strjoin(new_path, dir);
	return (new_path);
}

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

void	read_files(char *path, t_list *list, t_frmt *frmt)
{
	DIR				*dir;
	struct dirent	*ent;
	t_file			n_file;

	ft_putendl(path);
	if ((dir = opendir(path)) == NULL)
		ft_error("read_file: Failed to open Dir.");
	while ((ent = readdir(dir)) != NULL)
	{
		if (frmt->is_upper_r == 1 && ent->d_name[0] != '.')
			read_files(ft_new_path(path, ent->d_name), list, frmt);
		if (frmt->is_a == 0 && ent->d_name[0] == '.')
			continue;
		n_file.name = ent->d_name;
		ft_putendl(ent->d_name);
	}
	closedir(dir);
}
