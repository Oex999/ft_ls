/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:43 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 13:46:35 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		l_len;

	i = 0;
	l_len = ft_strlen(little);
	if (ft_strlen(big) >= ft_strlen(little) && little != NULL)
	{
		while (*big)
		{
			j = 0;
			while (big[i] == little[j] && big[i] && little[i])
			{
				j++;
				i++;
			}
			if (j == l_len)
				return ((char*)big);
			big++;
		}
	}
	return (NULL);
}
