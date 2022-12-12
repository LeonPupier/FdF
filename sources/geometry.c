/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:01:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/12 08:13:24 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static int	color_gradient(t_map *map, int z_start, int z_end)
{
	int	z;

	if (z_start >= z_end)
		z = z_start;
	else
		z = z_end;
	z *= map->zoom_height;
	if (z > 100)
		return (WHITE);
	else if (z > 50)
		return (BROWN);
	else if (z > 25)
		return (BROWN_DARK);
	else if (z > 5)
		return (GREEN_DARK);
	else if (z > 0)
		return (GREEN);
	return (BLUE);
}

void	isometric_view(t_map *map, t_point *xy)
{
	xy->x = (xy->x - xy->y) * cos(map->rotation / 3);
	if (xy->z != 0)
		xy->y = (xy->x + xy->y) * sin(map->rotation / 6) \
			- ((xy->z * map->zoom_height) / 11) * map->space;
	else
		xy->y = (xy->x + xy->y) * sin(map->rotation / 6) \
			- (xy->z / 11) * map->space;
}

void	draw_line(t_map *map, t_point xy_start, t_point xy_end)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	isometric_view(map, &xy_start);
	isometric_view(map, &xy_end);
	delta_x = (xy_end.x - xy_start.x);
	delta_y = (xy_end.y - xy_start.y);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		pixel_put(&map->img, xy_start.x + map->xy_gap.x + (SIZEX / 2), \
		xy_start.y + map->xy_gap.y + (SIZEY / 2), \
		color_gradient(map, xy_start.z, xy_end.z));
		xy_start.x += delta_x;
		xy_start.y += delta_y;
	}
}

void	draw_bottom_right(t_map *map, int length, int height, t_point xy_start)
{
	t_point	xy_end;

	if (length + 1 < map->length)
	{
		xy_end.x = xy_start.x + map->space;
		xy_end.y = xy_start.y;
		draw_line(map, xy_start, xy_end);
	}
	if (height + 1 < map->height)
	{
		xy_end.x = xy_start.x;
		xy_end.y = xy_start.y + map->space;
		draw_line(map, xy_start, xy_end);
	}
}
