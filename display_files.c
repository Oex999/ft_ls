/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:51:52 by oexall            #+#    #+#             */
/*   Updated: 2016/06/15 14:24:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_l_file(t_file *file)
{
	ft_putstr(file->permissions);
	ft_putstr("  ");
	ft_putnbr(file->nlinks);
	ft_putstr(" ");
	ft_putstr(file->username);
	ft_putstr("  ");
	ft_putstr(file->groupname);
	ft_printf(" %6d ", file->byte_size);
	ft_putstr(ft_substr(4, 12, file->date_modified));
	ft_putchar(' ');
	ft_putstr(file->name);
	ft_putchar('\n');
}

int		get_block_size(t_list **begin_list)
{
	int		size;
	t_list	*list;
	t_file	*file;

	list = *begin_list;
	size = 0;
	while (list)
	{
		file = (t_file *)list->data;
		size += (int)file->block_size;
		file = NULL;
		list = list->next;
	}
	return (size);
}

void	files(t_list **list, t_frmt *frmt)
{
	t_list	*files;
	t_file	*file;

	files = *list;
	while (files)
	{
		file = (t_file *)files->data;
		if (frmt->is_l)
			ft_print_l_file(file);
		else
			ft_putendl(file->name);
		file = NULL;
		files = files->next;
	}
}

void	dirs(t_list **list, t_frmt *frmt)
{
	t_list	*files;
	t_file	*file;

	files = *list;
	while (files && frmt->is_upper_r)
	{
		file = (t_file *)files->data;
		if (file->permissions[0] == 'd' && file->sub_dirs)
		{
			ft_printf("\n%s\n", file->path);
			display_files(&file->sub_dirs, frmt);
		}
		file = NULL;
		files = files->next;
	}
}

void	display_files(t_list **list, t_frmt *frmt)
{
	if (frmt->is_l)
		ft_printf("Total %d\n", get_block_size(list));
	files(list, frmt);
	if (frmt->is_upper_r)
		dirs(list, frmt);
}
