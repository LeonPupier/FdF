/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:16:12 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/12 10:26:55 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_printf("\033[07m[LOGS]  Display of the execution report:\033[00m\n");
	init_map(&map);
	if (argc == 2)
		map_parser(&map, argv[1]);
	else
		map_parser(&map, "test_maps/42.fdf");
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, SIZEX, SIZEY, "FdF - by Leon Pupier");
	map.img.img = mlx_new_image(map.mlx, SIZEX, SIZEY);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, \
									&map.img.line_length, &map.img.endian);
	map.img.bits_per_pixel /= 8;
	map.img.w = SIZEX;
	map.img.h = SIZEY;
	ft_printf("\033[32m[INFO]\033[00m	Generation of the window.\n");
	map.space = 30;
	mlx_hook(map.mlx_win, ON_DESTROY, 0, &quit_window, &map);
	mlx_hook(map.mlx_win, ON_KEYDOWN, 27, &check_keycode, &map);
	mlx_loop_hook(map.mlx, render_next_frame, &map);
	ft_printf("\033[32m[INFO]\033[00m	Display of the window to the user.\n");
	mlx_loop(map.mlx);
}
