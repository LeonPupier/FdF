/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:30:44 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/09 17:01:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	quit_window(t_map *map)
{
	int	idx;

	idx = -1;
	while (++idx < map->height)
		free(map->content[idx]);
	free(map->content);
	mlx_destroy_image(map->mlx, map->img.img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

void	display_text(t_map *map, int x, int y, char *text)
{
	mlx_string_put(map->mlx, map->mlx_win, x, y, WHITE, text);
}

int	check_keycode(int key_code, t_map *map)
{
	if (key_code == 53)
		quit_window(map);
	else if (key_code == 124)
		map->xy_gap.x -= map->space;
	else if (key_code == 123)
		map->xy_gap.x += map->space;
	else if (key_code == 126)
		map->xy_gap.y += map->space;
	else if (key_code == 125)
		map->xy_gap.y -= map->space;
	else if (key_code == 85 && map->zoom_height > 0.1)
		map->zoom_height -= 0.1;
	else if (key_code == 84)
		map->zoom_height += 0.1;
	else if (key_code == 83 && map->space < 100)
		map->space += 1;
	else if (key_code == 82 && map->space > 2)
		map->space -= 1;
	else if (key_code == 13)
		map->wtf_mode = 1;
	else if (key_code == 12)
		map->wtf_mode = 0;
	return (0);
}
