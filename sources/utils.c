/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:22:57 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/14 09:44:45 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	free_tab_str(char **tab)
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

int	loop_recover_tab(t_map *map, int fd)
{
	int		idx_tab;
	int		idx_line;
	char	*line;
	char	**tab;

	idx_line = 0;
	idx_tab = 0;
	while (idx_line < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab = ft_split(line, ' ');
		if (tab == NULL)
			return (free(line), 0);
		idx_tab = -1;
		while (tab[++idx_tab])
			map->content[idx_line][idx_tab] = ft_atoi(tab[idx_tab]);
		free(line);
		free_tab_str(tab);
		idx_line += 1;
	}
	return (1);
}

int	loop_count(t_map *map, int fd, int temp_count)
{
	int		idx_tab;
	char	*line;
	char	**tab;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (close(fd), 1);
		tab = ft_split(line, ' ');
		free(line);
		if (tab == NULL)
			return (close(fd), 0);
		map->height += 1;
		idx_tab = 0;
		while (tab[idx_tab])
			idx_tab++;
		if (idx_tab != temp_count && temp_count != -1)
			return (close(fd), 0);
		temp_count = idx_tab;
		map->length = idx_tab;
		free_tab_str(tab);
	}
	return (1);
}
