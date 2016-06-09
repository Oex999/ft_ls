/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back_special.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 06:49:25 by oexall            #+#    #+#             */
/*   Updated: 2016/06/09 11:41:08 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_list_push_back_special(t_list **list, size_t data_size, void *data)
{
	t_list	*tmp;
	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_special(data_size, data);
	}
	else
		*list = ft_create_special(data_size, data);
}
