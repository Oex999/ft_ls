/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:49:47 by oexall            #+#    #+#             */
/*   Updated: 2016/06/14 13:45:46 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# include <string.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_frmt
{
	int				is_l;
	int				is_upper_r;
	int				is_a;
	int				is_lower_r;
	int				is_t;
	char			*path;
}					t_frmt;

typedef struct		s_file
{
	char			*path;
	char			permissions[11];
	int				nlinks;
	char			*username;
	char			*groupname;
	int				byte_size;
	int				block_size;
	char			*date_modified;
	t_list			*sub_dirs;
	char			*name;
}					t_file;

t_list				*ft_create_elem(void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_clear_list(t_list **begin_list);
t_list				*ft_create_special(size_t data_size, void *data);
void				ft_list_push_back_special(t_list **list, size_t data_size,
					void *data);

void				sort(t_list **list, t_frmt *frmt);
void				ft_list_reverse(t_list **begin_list);

void				ft_error(char *error);
int					ft_isdir(char *path);
char				*ft_new_path(char *original, char *dir);

void				ft_process_args(t_frmt *frmt, char **argv, int count);

void				read_files(char *path, t_list **list, t_frmt *frmt);
void				ft_getstats(char *path, t_file *file);
void				display_files(t_list **list, t_frmt *frmt);
void				ft_print_l_file(t_file *file);
char				*ft_substr(int start, int len, char *str);
void				clear_file(t_file *file);

#endif
