/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 07:02:47 by oexall            #+#    #+#             */
/*   Updated: 2016/06/14 13:29:20 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getpermissions(struct stat *f_stat, t_file *file)
{
	file->permissions[0] = (S_ISDIR(f_stat->st_mode)) ? 'd' : '-';
	file->permissions[1] = (f_stat->st_mode & S_IRUSR) ? 'r' : '-';
	file->permissions[2] = (f_stat->st_mode & S_IWUSR) ? 'w' : '-';
	file->permissions[3] = (f_stat->st_mode & S_IXUSR) ? 'x' : '-';
	file->permissions[4] = (f_stat->st_mode & S_IRGRP) ? 'r' : '-';
	file->permissions[5] = (f_stat->st_mode & S_IWGRP) ? 'w' : '-';
	file->permissions[6] = (f_stat->st_mode & S_IXGRP) ? 'x' : '-';
	file->permissions[7] = (f_stat->st_mode & S_IROTH) ? 'r' : '-';
	file->permissions[8] = (f_stat->st_mode & S_IWOTH) ? 'w' : '-';
	file->permissions[9] = (f_stat->st_mode & S_IXOTH) ? 'x' : '-';
	file->permissions[10] = '\0';
}

void	ft_getstats(char *path, t_file *file)
{
	struct stat	f_stats;
	time_t		*mtime;

	if (stat(path, &f_stats) == -1)
		ft_error("ft_getstats: Failed to get stats of file");
	clear_file(file);
	mtime = &f_stats.st_mtimespec.tv_sec;
	ft_getpermissions(&f_stats, file);
	file->nlinks = (int)f_stats.st_nlink;
	file->username = getpwuid(f_stats.st_uid)->pw_name;
	file->groupname = getgrgid(f_stats.st_gid)->gr_name;
	file->byte_size = (int)f_stats.st_size;
	file->block_size = (int)f_stats.st_blocks;
	file->date_modified = ctime(mtime);
}
