/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:49:47 by oexall            #+#    #+#             */
/*   Updated: 2016/06/07 07:04:29 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>

typedef struct		s_list
{
	void			*data;
	int				size;
	struct s_list	*next;
}					t_list;

typedef struct	s_frmt
{
	int			is_l;
	int			is_upper_r;
	int			is_a;
	int			is_lower_r;
	int			is_t;
	char		*path;
}				t_frmt;

typedef struct	s_file
{
	char		permissions[11];
	int			nlinks;
	char		*username;
	char		*groupname;
	int			byte_size;
	void		*date_modified;
	char		*name;
}				t_file;

void			ft_error(char *error);

void			ft_process_args(t_frmt *frmt, char **argv, int count);

void			read_files(char *path, t_list *list, t_frmt *frmt, int is_rec);

#endif
