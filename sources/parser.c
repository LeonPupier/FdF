/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:54:57 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/04 18:08:13 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	free_tab_str(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}

static int	count_line_column(t_map *map, char *map_name)
{
	int		fd;
	int		idx_tab;
	char	*line;
	char	**tab;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	map->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (free(line), close(fd), 1);
		map->height += 1;
		tab = ft_split(line, ' ');
		free(line);
		idx_tab = 0;
		while (tab[idx_tab])
			idx_tab++;
		free_tab_str(tab);
		map->length = idx_tab;
	}
	close(fd);
	return (1);
}

static void	recover_tab(t_map *map, char *map_name)
{
	int		fd;
	int		idx_tab;
	int		idx_line;
	char	*line;
	char	**tab;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return ;
	idx_line = 0;
	idx_tab = 0;
	while (idx_line < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab = ft_split(line, ' ');
		idx_tab = -1;
		while (tab[++idx_tab])
			map->content[idx_line][idx_tab] = ft_atoi(tab[idx_tab]);
		free(line);
		free_tab_str(tab);
		idx_line += 1;
	}
	close(fd);
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
				return (0);
			idx++;
		}
		recover_tab(map, map_name);
		return (1);
	}
	else
		return (0);
}
