/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:47:46 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 13:06:13 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_move_right(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->x = zoom_move->x + 10;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->x);
}

int	ft_move_left(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->x = zoom_move->x - 10;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->x);
}

int	ft_move_up(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->y = zoom_move->y - 10;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->y);
}

int	ft_move_down(t_mlx *mlx_info, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	zoom_move->y = zoom_move->y + 10;
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	point_2d = ft_change_3d_to_2d(mlx_info->point_3d, zoom_move);
	mlx_info->point_2d = point_2d;
	ft_draw_pixel_and_image(mlx_info, mlx_info->point_2d);
	return (zoom_move->y);
}
