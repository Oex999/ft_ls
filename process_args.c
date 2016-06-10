/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:22:23 by oexall            #+#    #+#             */
/*   Updated: 2016/06/10 09:53:08 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_setfrmt(t_frmt *frmt)
{
	frmt->is_l = 0;
	frmt->is_upper_r = 0;
	frmt->is_a = 0;
	frmt->is_lower_r = 0;
	frmt->is_t = 0;
}

static int	one_of(char c, char *str)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void		process_flags(char *flags, t_frmt *frmt)
{
	if (*flags == '-')
		flags++;
	ft_setfrmt(frmt);
	while (*flags != '\0')
	{
		if (!(one_of(*flags, "lRart")))
			ft_error("process_flags: Invalid Argument");
		if (*flags == 'l')
			frmt->is_l = 1;
		else if (*flags == 'R')
			frmt->is_upper_r = 1;
		else if (*flags == 'a')
			frmt->is_a = 1;
		else if (*flags == 'r')
			frmt->is_lower_r = 1;
		else if (*flags == 't')
			frmt->is_t = 1;
		flags++;
	}
}

void		ft_process_args(t_frmt *frmt, char **argv, int count)
{
	int	i;

	i = 1;
	frmt->path = ".";
	if (count == 1 && argv[1][0] == '-')
		process_flags(argv[1], frmt);
	if (count == 1 && argv[1][0] != '-')
		frmt->path = argv[1];
	if (count == 2 && argv[1][0] == '-' && argv[2][0] != '-')
	{
		process_flags(argv[1], frmt);
		frmt->path = argv[2];
	}
}
