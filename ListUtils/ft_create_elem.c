/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:09:25 by oexall            #+#    #+#             */
/*   Updated: 2016/06/07 11:11:57 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))))
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}
