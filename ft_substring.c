/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:40:42 by oexall            #+#    #+#             */
/*   Updated: 2016/06/09 07:44:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_substr(int start, int len, char *str)
{
	char	*n_str;
	int		c;

	n_str = NULL;
	c = 0;
	if ((n_str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (c < len && (str[start + c] != '\0'))
		{
			n_str[c] = str[start + c];
			c++;
		}
	}
	return (n_str);
}
