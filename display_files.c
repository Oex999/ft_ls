/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:51:52 by oexall            #+#    #+#             */
/*   Updated: 2016/06/07 16:03:03 by oexall           ###   ########.fr       */
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
	ft_putstr("  ");
	ft_putstr(file->name);

	ft_putchar('\n');
}

void	display_files(t_list **list, t_frmt *frmt)
{
	t_list	*files;
	t_file	*file;

	files = *list;
	if (frmt->is_l)
		ft_putendl("\n\nTotal");
	while (files)
	{
		file = (t_file *)files->data;
		if (frmt->is_l)
		{
			ft_print_l_file(file);
		}
		else
			ft_print_l_file(file);
		file = NULL;
		files = files->next;
	}
}
