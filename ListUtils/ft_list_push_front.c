/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:39:09 by oexall            #+#    #+#             */
/*   Updated: 2016/06/07 11:42:14 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list_old;
	t_list	*list_new;

	list_old = *begin_list;
	list_new = ft_create_elem(data);
	if (list_old && list_new)
	{
		list_new->next = list_old;
		*begin_list = list_new;
	}
	else
		*begin_list = ft_create_elem(data);
}
