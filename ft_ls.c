/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:00:27 by oexall            #+#    #+#             */
/*   Updated: 2016/06/06 15:40:52 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	 t_frmt	frmt;
	 t_list	*list;

	 if (argc > 1)
		 ft_process_args(&frmt, argv, argc - 1);
	 list = NULL;
	 read_files(".", list, &frmt);
	 return (0);
}
