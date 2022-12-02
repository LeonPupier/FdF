/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:02:25 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 15:38:57 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw(t_data *img)
{
	t_point xy_start;
	t_point xy_end;

	xy_start.x = 100;
	xy_start.y = 100;
	xy_end.x = 500;
	xy_end.y = 100;
	draw_line(img, xy_start, xy_end, WHITE);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZEX, SIZEY, "FdF project");
	img.img = mlx_new_image(mlx, SIZEX, SIZEY);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.line_length, &img.endian);
	draw(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
