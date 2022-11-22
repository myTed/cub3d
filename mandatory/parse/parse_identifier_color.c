/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:10 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 20:49:31 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include "libft.h"
#include "ft_gnl.h"
#include <stdio.h>

static int	check_color_value(
			char **splited_str,
			int found_idx,
			t_parse_info *p_parse
		)
{
	int	idx;
	int	color_value;
	int	color_idx;

	if ((splited_str == 0) || (p_parse == 0))
		return (FAIL);
	idx = 0;
	while (idx < COLOR_NUM_MAX)
	{
		color_value = ft_atoi(splited_str[idx]);
		if ((color_value > COLOR_VALUE_MAX) || (color_value < COLOR_VALUE_MIN))
		{
			printf("Error\n: color value more than 255 or less than 0!\n");
			return (FAIL);
		}
		color_idx = 2 - idx;
		if (found_idx == FLOOR_IDX)
			((unsigned char *)(&(p_parse->floor)))[color_idx] = color_value;
		else if (found_idx == CEILING_IDX)
			((unsigned char *)(&(p_parse->ceiling)))[color_idx] = color_value;
		idx++;
	}
	return (SUCCESS);
}

static int	check_color_cnt(
				char **splited_str
			)
{
	int	idx;

	if (splited_str == 0)
		return (FAIL);
	idx = 0;
	while (splited_str[idx])
		idx++;
	if (idx != COLOR_NUM_MAX)
	{
		printf("Error\n: color should be only 3 colors\n");
		return (FAIL);
	}
	return (SUCCESS);
}

static int	check_color_comma(
				char *color_str
			)
{
	int	comma_cnt;
	int	idx;

	if (color_str == 0)
		return (FAIL);
	comma_cnt = 0;
	idx = 0;
	while (color_str[idx])
	{
		if (color_str[idx] == ',')
				comma_cnt++;
		idx++;
	}
	if (comma_cnt != 2)
	{
		printf("Error\n: comma cnt should be 2!");
		return (FAIL);
	}
	return (SUCCESS);
}

int	free_split(char **split);

int	check_color(
		char *color_str,
		int found_idx,
		t_parse_info *p_parse
	)
{
	char	**splited_str;

	if ((color_str == 0) || (p_parse == 0))
		return (FAIL);
	splited_str = ft_split(color_str, ',');
	if (splited_str == 0)
	{
		perror("Error\n");
		return (FAIL);
	}
	if ((check_color_comma(color_str) == FAIL) || \
		(check_color_cnt(splited_str) == FAIL) || \
		(check_color_value(splited_str, found_idx, p_parse) == FAIL))
	{
		free_split(splited_str);
		return (FAIL);
	}
	free_split(splited_str);
	return (SUCCESS);
}
