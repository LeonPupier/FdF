/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:01:07 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 15:41:30 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	draw_line(t_data *img, t_point xy_start, t_point xy_end, int color)
{
	int	x;
	int	y;
	int	x_sign;
	int	y_sign;

	x = xy_start.x;
	y = xy_start.y;
	x_sign = 1;
	if (x > xy_end.x)
		x_sign = -1;
	y_sign = 1;
	if (y > xy_end.y)
		y_sign = -1;
	while (x != xy_end.x)
	{
		while (y != xy_end.y)
		{
			my_mlx_pixel_put(img, x, y, color);
			x += x_sign;
		}
		y += y_sign;
	}
}
