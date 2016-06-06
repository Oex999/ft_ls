/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:58:23 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/10 07:55:50 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ret = (char*)malloc(sizeof(char) * i);
	j = -1;
	while (++j < i)
		ret[j] = s1[j];
	ret[j] = '\0';
	return (ret);
}
