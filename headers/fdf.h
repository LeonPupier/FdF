/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:51 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/04 18:25:15 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Librairies
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

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

// Key events
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// Point structure
typedef struct s_point {
	double		x;
	double		y;
	double		z;
}	t_point;

// Image structure
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// Map informations
typedef struct s_map {
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		**content;
	int		length;
	int		height;
	int		space;
	int		color_line;
	int		color_focus;
	double	rotation;
}	t_map;

// fdf.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// parser.c
int		map_parser(t_map *map, char *map_name);

// geometry.c
void	isometric_view(t_map *map, t_point xy);
void	draw_line(t_map *map, t_point xy_start, t_point xy_end);
void	draw_bottom_right(t_map *map, int length, int height, t_point xy_start);

#endif