/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:01:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/05 15:17:35 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	isometric_view(t_map *map, t_point xy)
{
	if (xy.x < SIZEX && xy.y < SIZEY)
	{
		xy.x = (xy.x - xy.y) * cos(map->rotation);
		xy.y = (xy.x + xy.y) * sin(map->rotation) - xy.z;
		if (map->xy_gap.x + xy.x > 0 && map->xy_gap.y + xy.y > 0 \
			&& map->xy_gap.x + xy.x < SIZEX && map->xy_gap.y + xy.y < SIZEY)
		{
			if (xy.z == 0)
				my_mlx_pixel_put(&map->img, map->xy_gap.x + xy.x, \
					map->xy_gap.y + xy.y, map->color_line);
			else
				my_mlx_pixel_put(&map->img, map->xy_gap.x + xy.x, \
					map->xy_gap.y + xy.y, map->color_focus);
		}
	}
}

void	draw_line(t_map *map, t_point xy_start, t_point xy_end)
{
	t_point	xy;
	int		x_sign;
	int		y_sign;

	xy.x = xy_start.x;
	xy.y = xy_start.y;
	xy.z = xy_start.z;
	x_sign = 1;
	if (xy.x > xy_end.x)
		x_sign = -1;
	y_sign = 1;
	if (xy.y > xy_end.y)
		y_sign = -1;
	while (xy.y != xy_end.y || xy.x != xy_end.x)
	{
		if (xy.x + x_sign == xy_end.x)
			xy.x += x_sign;
		if (xy.y + y_sign == xy_end.y)
			xy.y += y_sign;
		if (xy.x != xy_end.x)
			xy.x += x_sign;
		if (xy.y != xy_end.y)
			xy.y += y_sign;
		isometric_view(map, xy);
	}
}

void	draw_bottom_right(t_map *map, int length, int height, t_point xy_start)
{
	t_point	xy_end;

	if (length + 1 < map->length)
	{
		xy_end.x = xy_start.x + map->space;
		xy_end.y = xy_start.y;
		if (map->content[height][length] == 0)
			draw_line(map, xy_start, xy_end);
		else
			draw_line(map, xy_start, xy_end);
	}
	if (height + 1 < map->height)
	{
		xy_end.x = xy_start.x;
		xy_end.y = xy_start.y + map->space;
		if (map->content[height][length] == 0)
			draw_line(map, xy_start, xy_end);
		else
			draw_line(map, xy_start, xy_end);
	}
}
