/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:06:16 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/26 20:46:49 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>
*/
static size_t	get_word_cnt(char const *s, char c)
{
	size_t	idx;
	size_t	word_cnt;
	int		find_delim;
	int		pre_find_delim;

	idx = 0;
	word_cnt = 0;
	find_delim = 1;
	pre_find_delim = find_delim;
	while (s[idx] != 0)
	{
		if (s[idx] == c)
			find_delim = 1;
		else
			find_delim = 0;
		if (pre_find_delim == 1 && find_delim == 0)
			word_cnt++;
		pre_find_delim = find_delim;
		idx++;
	}
	return (word_cnt);
}

static void	fill_start_end_idx(char const *s, char c, int *pos_arry)
{
	int		idx;
	int		pos_idx;
	int		find_delim;
	int		prev_find_delim;

	idx = 0;
	pos_idx = 0;
	find_delim = 1;
	prev_find_delim = find_delim;
	while (s[idx] != 0)
	{
		if (s[idx] == c)
			find_delim = 1;
		else
			find_delim = 0;
		if ((prev_find_delim == 1) && (find_delim == 0))
			pos_arry[pos_idx++] = idx;
		if ((prev_find_delim == 0) && (find_delim == 1))
			pos_arry[pos_idx++] = idx - 1;
		prev_find_delim = find_delim;
		idx++;
	}
	if (prev_find_delim == 0)
		pos_arry[pos_idx++] = idx - 1;
}

static void	free_split(char **str, int cnt)
{
	int	idx;

	idx = 0;
	while (idx < cnt)
		free(str[idx]);
	free(str);
}

static char	**make_word_arry(char const *s, int *p_arry, int word_cnt)
{
	char	**str;
	int		idx;
	int		pidx;

	str = malloc(sizeof(char *) * (word_cnt + 1));
	if (str == NULL)
		return (NULL);
	str[word_cnt] = 0;
	idx = 0;
	pidx = 0;
	while (idx < word_cnt)
	{
		str[idx] = malloc(sizeof(char) * (p_arry[pidx + 1] - p_arry[pidx] + 2));
		if (str[idx] == NULL)
		{
			free_split(str, idx);
			return (NULL);
		}
		ft_memcpy(str[idx], s + p_arry[pidx], \
			p_arry[pidx + 1] - p_arry[pidx] + 1);
		str[idx][p_arry[pidx + 1] - p_arry[pidx] + 1] = 0;
		idx++;
		pidx += 2;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		*pos_idx_arry;
	int		word_cnt;

	if (s == 0)
		return (0);
	word_cnt = get_word_cnt(s, c);
	pos_idx_arry = malloc(sizeof(int) * (word_cnt * 2));
	if (pos_idx_arry == NULL)
		return (NULL);
	fill_start_end_idx(s, c, pos_idx_arry);
	str = make_word_arry(s, pos_idx_arry, word_cnt);
	free(pos_idx_arry);
	return (str);
}
/*
int	main(int argc, char *argv[])
{
	char	**str;
	int		idx;

	if (argc != 3)
		return (0);
	str = ft_split(argv[1], argv[2][0]);
	idx = 0;
	while (str[idx] != 0)
	{
		printf("%s\n", str[idx]);
		idx++;
	}
	return (0);
}
*/
