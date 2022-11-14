/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:14:51 by kyolee            #+#    #+#             */
/*   Updated: 2022/06/14 23:17:59 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H
# include <stddef.h>
# include <sys/types.h>
# define GNL_BUFFER_SIZE 128

typedef struct s_list_gnl
{
	int					fd;
	char				*left;
	size_t				left_len;
	struct s_list_gnl	*next;
}	t_list_gnl;

int			is_found_chr(const char *s, int c, size_t len);
int			read_line(int fd, char *buff, char **pstr);
int			add_prev_line(int fd, char **pline, t_list_gnl **pplist);
int			save_line(int fd, char **pline, t_list_gnl **pplist);
t_list_gnl	*ft_lstnew_gnl(int fd, void *str, size_t str_len);
void		ft_lstadd_back_gnl(t_list_gnl **lst, t_list_gnl *new);
void		ft_lstdel_gnl(t_list_gnl **lst, int fd);
size_t		ft_strlen_gnl(void *src);
char		*ft_strjoin_gnl(
				char const *s1,
				char const *s2,
				size_t s1_len,
				size_t s2_len
				);
char		*get_next_line(int fd);
#endif
