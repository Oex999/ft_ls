/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 06:43:51 by oexall            #+#    #+#             */
/*   Updated: 2016/06/14 13:48:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_list	*ft_create_special(size_t data_size, void *data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list *));
	if (tmp)
	{
		tmp->data = malloc(data_size);
		//tmp->data = ft_memcpy(tmp->data, data, data_size);
		tmp->data = memcpy(tmp->data, data, data_size);
		tmp->next = NULL;
	}
	else
		return (NULL);
	return (tmp);
}
