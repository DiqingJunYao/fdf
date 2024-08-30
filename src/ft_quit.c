/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:48:41 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 13:20:18 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_quit(t_mlx *mlx_info)
{
	ft_free_list_3d(mlx_info->point_3d);
	ft_free_list_2d(mlx_info->point_2d);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->mlx_image_ptr);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->mlx_window_ptr);
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->mlx_window_ptr);
	mlx_destroy_display(mlx_info->mlx_ptr);
	free (mlx_info->mlx_ptr);
	free (mlx_info->zoom_move);
	free (mlx_info);
	exit (EXIT_SUCCESS);
}
