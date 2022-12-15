/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:54:57 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/15 13:32:39 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static int	count_line_column(t_map *map, char *map_name)
{
	int		fd;
	int		temp_count;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map->height = 0;
	temp_count = -1;
	if (loop_count(map, fd, temp_count) == 0)
		return (0);
	close(fd);
	return (1);
}

static int	recover_tab(t_map *map, char *map_name)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (loop_recover_tab(map, fd) == 0)
		return (0);
	close(fd);
	return (1);
}

int	map_parser(t_map *map, char *map_name)
{
	int		idx;

	if (count_line_column(map, map_name) == 1)
	{
		map->content = malloc(sizeof(int *) * map->height);
		if (map->content == NULL)
			return (0);
		idx = 0;
		while (idx < map->height)
		{
			map->content[idx] = malloc(sizeof(int) * map->length);
			if (map->content[idx] == NULL)
				return (free_tab_int(map->content), 0);
			idx++;
		}
		recover_tab(map, map_name);
		ft_printf("\033[32m[INFO]\033[00m	The map has been correctly loaded.\n");
		return (1);
	}
	else
	{
		ft_printf("\033[31m[ERROR]\033[00m	The map encountered a problem.\n");
		exit(1);
	}
}
