/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:51 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/15 13:46:31 by lpupier          ###   ########.fr       */
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
# define WHITE		0x00FFFFFF
# define GREY		0x00808080
# define BLACK		0x00000000
# define BROWN		0x00C47B1E
# define BROWN_DARK	0x007B4B0D
# define RED		0x00FF0000
# define YELLOW		0x00FFFF00
# define GREEN		0x00008000
# define GREEN_DARK	0x00175912
# define BLUE		0x000000FF
# define PURPLE		0x00800080

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
	int		w;
	int		h;
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
	int		wtf_mode;
	int		wtf_count;
	double	rotation;
	double	zoom_height;
	t_point	xy_gap;
	t_point	xy_zoom;
}	t_map;

// main.c
int		main(int argc, char **argv);

// map.c
void	pixel_put(t_data *data, int x, int y, int color);
void	init_map(t_map *map);
int		render_next_frame(t_map *map);
void	draw_map(t_map *map);

// parser.c
int		map_parser(t_map *map, char *map_name);

// geometry.c
void	isometric_view(t_map *map, t_point *xy);
void	draw_line(t_map *map, t_point xy_start, t_point xy_end);

// events.c
int		quit_window(t_map *map);
void	display_text(t_map *map, int x, int y, char *text);
int		check_keycode(int keycode, t_map *map);
int		check_keycode_mouse(int key_code, int x, int y, t_map *map);

// utils.c
void	free_tab_str(char **tab);
void	free_tab_int(int **tab);
int		loop_recover_tab(t_map *map, int fd);
int		loop_count(t_map *map, int fd, int temp_count);

#endif