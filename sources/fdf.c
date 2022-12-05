/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:02:25 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/05 15:56:42 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	init_map(t_map *map)
{
	map->space = 30;
	map->color_line = WHITE;
	map->color_focus = RED;
	map->rotation = 0.8;
	map->xy_gap.x = 0;
	map->xy_gap.y = 0;
}

int	render_next_frame(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, SIZEX, SIZEY);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, \
									&map->img.line_length, &map->img.endian);
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
	return (0);
}

void	draw_map(t_map *map)
{
	t_point	xy;
	int		count_line;
	int		count_column;

	xy.y = 0;
	count_line = -1;
	while (++count_line < map->height)
	{
		count_column = -1;
		xy.x = SIZEX - (map->length * map->space);
		while (++count_column < map->length)
		{
			xy.z = map->content[count_line][count_column];
			draw_bottom_right(map, count_column, count_line, xy);
			if (xy.z == 0)
				isometric_view(map, xy);
			else
				isometric_view(map, xy);
			xy.x += map->space;
		}
		xy.y += map->space;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	init_map(&map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, SIZEX, SIZEY, "FdF - by Leon Pupier");
	map.img.img = mlx_new_image(map.mlx, SIZEX, SIZEY);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, \
									&map.img.line_length, &map.img.endian);
	if (argc == 2)
		map_parser(&map, argv[1]);
	else
		map_parser(&map, "test_maps/42.fdf");
	mlx_hook(map.mlx_win, ON_KEYDOWN, 27, &check_keycode, &map);
	mlx_loop_hook(map.mlx, render_next_frame, &map);
	mlx_loop(map.mlx);
}
