/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 10:38:13 by oexall            #+#    #+#             */
/*   Updated: 2016/06/17 07:25:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp = NULL;
	tmp = *begin_list;
	if (!(tmp || tmp->next))
		return ;
	tmp1 = tmp->next;
	tmp2 = tmp1->next;
	tmp->next = NULL;
	tmp1->next = tmp;
	while (tmp2)
	{
		tmp = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		tmp1->next = tmp;
	}
	*begin_list = tmp1;
}
