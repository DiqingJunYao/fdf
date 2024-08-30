/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:27:09 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 18:06:45 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_zoom_in(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->z = zoom_move->z + 1;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->z);
}

int	ft_zoom_out(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->z = zoom_move->z - 1;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->z);
}

int	ft_turn_up(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->angle_degree = zoom_move->angle_degree - 1;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->angle_degree);
}

int	ft_put_down(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->angle_degree = zoom_move->angle_degree + 1;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->angle_degree);
}

int	ft_mouse_hook(int button, int x, int y, t_mlx *mlx_info)
{
	if (button == 4 && x <= 10 && y <= 10)
		mlx_info->zoom_move->z = ft_zoom_in(mlx_info, mlx_info->zoom_move);
	if (button == 5 && x <= 10 && y <= 10)
		mlx_info->zoom_move->z = ft_zoom_out(mlx_info, mlx_info->zoom_move);
	if (button == 1 && x <= 10 && y <= 10)
		mlx_info->zoom_move->angle_degree
			= ft_turn_up(mlx_info, mlx_info->zoom_move);
	if (button == 3 && x <= 10 && y <= 10)
		mlx_info->zoom_move->angle_degree
			= ft_put_down(mlx_info, mlx_info->zoom_move);
	return (0);
}
