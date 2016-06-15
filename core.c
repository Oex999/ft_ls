/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:34:12 by oexall            #+#    #+#             */
/*   Updated: 2016/06/14 13:31:42 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valid_dir(char *path, char *name, char type)
{
	char *full_path;

	full_path = ft_new_path(path, name);
	if (ft_isdir(full_path) && ft_strncmp(name, "..", 2) != 0
			&& ft_strcmp(name, ".") != 0 && type == 'd')
		return (1);
	return (0);
}

void	clear_file(t_file *file)
{
	file->path = NULL;
	ft_memset(file->permissions, 0, 11);
	file->nlinks = 0;
	file->username = NULL;
	file->groupname = NULL;
	file->byte_size = 0;
	file->block_size = 0;
	file->date_modified = NULL;
	file->sub_dirs = NULL;
	file->name = NULL;
}

void	read_files(char *path, t_list **list, t_frmt *frmt)
{
	DIR				*dir;
	struct dirent	*ent;
	t_file			*n_file;

	dir = NULL;
	ent = NULL;
	if ((dir = opendir(path)) == NULL)
		ft_error("read_file: Failed to open Dir.");
	while ((ent = readdir(dir)) != NULL)
	{
		if (frmt->is_a == 0 && ent->d_name[0] == '.')
			continue;
		if (!(n_file = (t_file *)malloc(sizeof(t_file))))
			ft_error("read_files: failed to malloc n_file.");
		ft_getstats(ft_new_path(path, ent->d_name), n_file);
		n_file->name = ent->d_name;
		n_file->path = ft_new_path(path, n_file->name);
		if (is_valid_dir(path, n_file->name, n_file->permissions[0])
				&& frmt->is_upper_r)
			read_files(ft_new_path(path, ent->d_name), &n_file->sub_dirs, frmt);
		ft_list_push_back_special(list, sizeof(t_file), n_file);
		free(n_file);
	}
	free(ent);
	closedir(dir);
}
