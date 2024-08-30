/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:25:44 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 20:11:23 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include "./../minilibx-linux/mlx.h"
# include "./../get_next_line/get_next_line.h"
# include "./../libft/libft.h"

typedef struct s_3d_point
{
	double				x;
	double				y;
	double				z;
	struct s_3d_point	*next;
}	t_3d_point;

typedef struct s_2d_point
{
	double				x;
	double				y;
	double				o_x;
	double				o_y;
	double				o_z;
	struct s_2d_point	*next;
}	t_2d_point;

typedef struct s_zoom_move
{
	int		x;
	int		y;
	int		z;
	int		angle_degree;
	double	angle_radians;
}	t_zoom_move;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_window_ptr;
	void		*mlx_image_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*data_addr;
	t_2d_point	*point_2d;
	t_3d_point	*point_3d;
	t_zoom_move	*zoom_move;
}	t_mlx;

typedef struct s_draw_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_draw_line;

t_2d_point	*ft_change_3d_to_2d(t_3d_point *point_3d, t_zoom_move *zoom_move);
int			ft_check_pixel(t_2d_point *point_2d);
void		draw_line(t_2d_point *start, t_2d_point *end,
				int color, t_mlx *mlx_info);
void		ft_draw_pixel_and_image(t_mlx *mlx_info, t_2d_point *point_2d);
void		ft_free_list_3d(t_3d_point *point);
void		ft_free_list_2d(t_2d_point *point);
int			ft_move_right(t_mlx *mlx_info, t_zoom_move *zoom_move);
int			ft_move_left(t_mlx *mlx_info, t_zoom_move *zoom_move);
int			ft_move_up(t_mlx *mlx_info, t_zoom_move *zoom_move);
int			ft_move_down(t_mlx *mlx_info, t_zoom_move *zoom_move);
void		ft_free_double_pointer(char **pointer);
void		ft_put_pixel(t_mlx *mlx_info,
				t_2d_point *point_2d, t_2d_point *start_point);
void		ft_quit(t_mlx *mlx_info);
t_3d_point	*initialize_points(int fd);
t_3d_point	*link_points(int fd, t_3d_point *point);
t_3d_point	*ft_read_and_fill(char *file_name);
void		ft_set_mlx(char **argv, t_2d_point *point_2d,
				t_3d_point *point_3d, t_zoom_move *zoom_move);
int			ft_mouse_hook(int button, int x, int y, t_mlx *mlx_info);

//this is the helper function
void		ft_print_list_3d(t_3d_point *point_3d);
void		ft_print_list_2d(t_2d_point *point_2d);

#endif