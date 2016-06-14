/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:00:27 by oexall            #+#    #+#             */
/*   Updated: 2016/06/13 16:18:51 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_frmt	frmt;
	t_list	*list;

	list = NULL;
	ft_process_args(&frmt, argv, argc - 1);
	read_files(frmt.path, &list, &frmt);
	sort(&list, &frmt);
	display_files(&list, &frmt);
	ft_clear_list(&list);
	return (0);
}
