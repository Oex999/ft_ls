/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:34:12 by oexall            #+#    #+#             */
/*   Updated: 2016/06/07 15:19:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_files(char *path, t_list **list, t_frmt *frmt)
{
	DIR				*dir;
	struct dirent	*ent;
	t_file			*n_file;

	n_file = NULL;
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
		ft_print_l_file(n_file); //REMOVE REMOVE
		if (n_file->permissions[0] == 'd' && n_file->name[0] != '.'
				&& ft_strncmp(n_file->name, "..", 2) != 0 && frmt->is_upper_r)
			read_files(ft_new_path(path, ent->d_name), &(n_file->sub_dirs), frmt);
		ft_list_push_back(list, (void *)n_file);
		free(n_file);
	}
	closedir(dir);
}
