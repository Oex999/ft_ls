/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:00:27 by oexall            #+#    #+#             */
/*   Updated: 2016/06/14 09:52:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clear_special(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;
	t_file	*file;

	list = *begin_list;
	tmp = NULL;
	file = NULL;
	while (list)
	{
		file = (t_file *)list->data;
		if (file->sub_dirs != NULL)
			ft_clear_special(&file->sub_dirs);
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_frmt	frmt;
	t_list	*list;

	list = NULL;
	ft_process_args(&frmt, argv, argc - 1);
	read_files(frmt.path, &list, &frmt);
	sort(&list, &frmt);
	display_files(&list, &frmt);
	ft_clear_special(&list);
	return (0);
}
