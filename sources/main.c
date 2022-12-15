/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:16:12 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/15 13:44:51 by lpupier          ###   ########.fr       */
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
		return (ft_printf("\033[31m[ERROR]\033[00m	No map given.\n"), 0);
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
	mlx_hook(map.mlx_win, ON_MOUSEDOWN, 27, &check_keycode_mouse, &map);
	mlx_loop_hook(map.mlx, render_next_frame, &map);
	ft_printf("\033[32m[INFO]\033[00m	Display of the window to the user.\n");
	mlx_loop(map.mlx);
}
