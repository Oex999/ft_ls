/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 13:06:12 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/27 15:17:49 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(const int fd, char **file)
{
	char		*buff;
	char		*fresh;
	int			read_bytes;

	if (!(buff = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		fresh = ft_strjoin(*file, buff);
		if (!(fresh))
			return (-1);
		free(*file);
		*file = fresh;
	}
	if (buff)
		free(buff);
	return (read_bytes);
}

int			get_next_line(const int fd, char **line)
{
	static char	*file;
	char		*endl_index;
	int			ret;

	if (!file && !(file = (char*)malloc(sizeof(char))))
		return (-1);
	endl_index = ft_strchr(file, '\n');
	while (endl_index == NULL)
	{
		if ((ret = ft_read(fd, &file)) == 0)
		{
			if ((endl_index = ft_strchr(file, '\0')) == file)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(file, '\n');
	}
	if (!(*line = ft_strsub(file, 0, endl_index - file)))
		return (-1);
	endl_index = ft_strdup(endl_index + 1);
	free(file);
	file = endl_index;
	return (1);
}
