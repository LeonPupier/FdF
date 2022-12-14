/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:02:25 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/12 09:31:06 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->w || y < 0 || y >= data->h)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel));
	*(unsigned int *)dst = color;
}

void	init_map(t_map *map)
{
	map->space = 30;
	map->rotation = 3.14;
	map->xy_gap.x = 0;
	map->xy_gap.y = 0;
	map->zoom_height = 1;
	map->wtf_mode = 0;
	map->wtf_count = 0;
}

void	check_line(t_map *map, int x, int y)
{
	t_point	xy_start;
	t_point	xy_end;

	if (x + 1 < map->length)
	{
		xy_start.x = x * map->space;
		xy_start.y = y * map->space;
		xy_end.x = (x + 1) * map->space;
		xy_end.y = y * map->space;
		xy_start.z = map->content[y][x];
		xy_end.z = map->content[y][x + 1];
		draw_line(map, xy_start, xy_end);
	}
	if (y + 1 < map->height)
	{
		xy_start.x = x * map->space;
		xy_start.y = y * map->space;
		xy_end.x = x * map->space;
		xy_end.y = (y + 1) * map->space;
		xy_start.z = map->content[y][x];
		xy_end.z = map->content[y + 1][x];
		draw_line(map, xy_start, xy_end);
	}
}

void	draw_map(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			check_line(map, x, y);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_map *map)
{
	ft_memset(map->img.addr, 0, map->img.h * map->img.line_length);
	if (map->wtf_mode)
	{
		map->rotation += 0.1;
	}
	else
		map->rotation = 3.14;
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
	if (map->wtf_mode && map->wtf_count > 2 && map->wtf_count < 7)
		mlx_string_put(map->mlx, map->mlx_win, SIZEX / 2 - 110, 0, RED, \
		"!! WTF MODE ACTIVED !!");
	if (map->wtf_count == 10)
		map->wtf_count = 0;
	map->wtf_count += 1;
	display_text(map, 0, 0, "Zoom +/-:    1 / 0");
	display_text(map, 0, 20, "Height +/-:  2 / 3");
	display_text(map, 0, 40, "Move map:    Arrows");
	return (0);
}
