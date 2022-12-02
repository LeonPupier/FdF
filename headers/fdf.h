/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:51 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 16:12:56 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Librairies
# include "../mlx/mlx.h"

// Window size (x, y)
# ifndef SIZEX
#  define SIZEX 1920
# endif

# ifndef SIZEY
#  define SIZEY 1080
# endif

// Colors
# define WHITE	0x00FFFFFF
# define GREY	0x00808080
# define BLACK	0x00000000
# define RED	0x00FF0000
# define YELLOW	0x00FFFF00
# define GREEN	0x00008000
# define BLUE	0x000000FF
# define PURPLE	0x00800080

// Point structure
typedef struct s_point {
	int		x;
	int		y;
}	t_point;

// Image structure
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// fdf.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// geometry.c
void	draw_line(t_data *img, t_point xy_start, t_point xy_end, int color);

#endif