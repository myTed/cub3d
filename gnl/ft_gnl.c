/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:24:09 by kyolee            #+#    #+#             */
/*   Updated: 2022/06/14 23:14:19 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "ft_gnl.h"

int	is_found_chr(const char *s, int c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (s[idx] == (char)c)
			return (1);
		idx++;
	}
	return (0);
}

int	read_line(int fd, char *buff, char **pstr)
{
	ssize_t	read_cnt;
	ssize_t	tmp_cnt;
	char	*tmp;

	tmp_cnt = 0;
	while (1)
	{
		read_cnt = read(fd, buff, GNL_BUFFER_SIZE);
		if (read_cnt == 0)
			break ;
		if (read_cnt < 0)
			return (-1);
		tmp = ft_strjoin_gnl(*pstr, buff, tmp_cnt, read_cnt);
		if (tmp == 0)
			return (-1);
		free(*pstr);
		*pstr = tmp;
		if (is_found_chr(*pstr, '\n', tmp_cnt + read_cnt))
			break ;
		tmp_cnt += read_cnt;
	}
	return (0);
}

int	add_prev_line(int fd, char **pline, t_list_gnl **pplist)
{
	char		*tmp;
	size_t		line_len;
	t_list_gnl	*plist;

	line_len = 0;
	if (*pline != 0)
		line_len = ft_strlen_gnl(*pline);
	plist = *pplist;
	while (plist != NULL)
	{
		if (plist->fd == fd)
		{
			tmp = ft_strjoin_gnl(plist->left, *pline, plist->left_len,
					line_len);
			if (tmp == 0)
				return (-1);
			ft_lstdel_gnl(pplist, fd);
			free(*pline);
			*pline = tmp;
			break ;
		}
		plist = plist->next;
	}
	return (0);
}

int	save_line(int fd, char **pline, t_list_gnl **pplist)
{
	size_t		line_len;
	size_t		ent_pos;
	char		*tmp;
	t_list_gnl	*new_lst;

	if (*pline == 0)
		return (0);
	line_len = ft_strlen_gnl(*pline);
	if (is_found_chr(*pline, '\n', line_len - 1) == 0)
		return (0);
	ent_pos = 0;
	while ((*pline)[ent_pos] != '\n')
		ent_pos++;
	tmp = ft_strjoin_gnl(&(*pline)[ent_pos + 1], 0, line_len - ent_pos - 1, 0);
	if (tmp == 0)
		return (-1);
	new_lst = ft_lstnew_gnl(fd, tmp, line_len - ent_pos - 1);
	if (new_lst == 0)
	{
		free(tmp);
		return (-1);
	}
	ft_lstadd_back_gnl(pplist, new_lst);
	(*pline)[ent_pos + 1] = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	char				*buff;
	char				*line;
	static t_list_gnl	*plist;
	int					error;

	if (fd < 0)
		return (0);
	buff = malloc(sizeof(char) * GNL_BUFFER_SIZE);
	if (buff == 0)
		return (0);
	line = 0;
	error = 0;
	if (read_line(fd, buff, &line) < 0)
		error = 1;
	if (!error && (add_prev_line(fd, &line, &plist) < 0))
		error = 1;
	if (!error && (save_line(fd, &line, &plist) < 0))
		error = 1;
	if (error)
	{
		free(line);
		line = 0;
	}
	free(buff);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*str;
	int		idx;
	
	fd = open("aaa.txt", O_RDONLY);
	
	fd = 0;
	while ((str = get_next_line(fd)) != 0)
	{
		printf("%s", str);
		fflush(stdout);
		free(str);
		idx++;
	}
	
	if (fd)
		close(fd);
	
	return (0);
}
*/
/*
int	main(void)
{
	int		fd[3];
	char	*str;
	int		idx;

	fd[0] = open("aaa.txt", O_RDONLY);
	if (fd[0] < 0)
		return (-1);
	fd[1] = open("bbb.txt", O_RDONLY);
	if (fd[1] < 0)
		return (-1);
	fd[2] = open("ccc.txt", O_RDONLY);
	if (fd[2] < 0)
		return (-1);
	idx = 0;
	while (1)
	{
		str = get_next_line(fd[idx % 3]);
		printf("%s", str);
		fflush(stdout);
		free(str);
		idx++;
	}
	
	if (fd)
		close(fd);
	
	return (0);
}
*/
/*
int	main(void)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		printf("%s", str);
		fflush(stdout);
		if (strncmp(str, "eof", 3) == 0)
			break;
		free(str);
	}
	free(str);
	return (0);
}
*/
