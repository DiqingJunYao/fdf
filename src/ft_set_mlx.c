/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:28:58 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 13:29:43 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_pixel_and_image(t_mlx *mlx_info, t_2d_point *point_2d)
{
	mlx_info->mlx_image_ptr = mlx_new_image(mlx_info->mlx_ptr, 3000, 1500);
	mlx_info->data_addr = mlx_get_data_addr(mlx_info->mlx_image_ptr,
			&mlx_info->bits_per_pixel, &mlx_info->size_line, &mlx_info->endian);
	ft_put_pixel(mlx_info, point_2d, point_2d);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->mlx_window_ptr, mlx_info->mlx_image_ptr, 0, 0);
	if (mlx_info->mlx_image_ptr == NULL)
	{
		write(2, "Failed to draw the image", 24);
		ft_free_list_2d(point_2d);
		exit (EXIT_FAILURE);
	}
}

int	ft_key_hook(int key, t_mlx *mlx_info)
{
	if (key == 65307)
		ft_quit(mlx_info);
	if (key == 100)
		mlx_info->zoom_move->x = ft_move_right(mlx_info, mlx_info->zoom_move);
	if (key == 97)
		mlx_info->zoom_move->x = ft_move_left(mlx_info, mlx_info->zoom_move);
	if (key == 119)
		mlx_info->zoom_move->y = ft_move_up(mlx_info, mlx_info->zoom_move);
	if (key == 115)
		mlx_info->zoom_move->y = ft_move_down(mlx_info, mlx_info->zoom_move);
	return (0);
}

int	ft_mlx_hook(t_mlx *mlx_info)
{
	ft_quit(mlx_info);
	return (0);
}

void	ft_handle_mouse_and_keyboard(t_mlx *mlx_info)
{
	mlx_key_hook(mlx_info->mlx_window_ptr, ft_key_hook, mlx_info);
	mlx_hook(mlx_info->mlx_window_ptr, 17, 0, ft_mlx_hook, mlx_info);
	mlx_mouse_hook(mlx_info->mlx_window_ptr, ft_mouse_hook, mlx_info);
	mlx_loop(mlx_info->mlx_ptr);
}

void	ft_set_mlx(char **argv, t_2d_point *point_2d,
			t_3d_point *point_3d, t_zoom_move *zoom_move)
{
	t_mlx	*mlx_info;

	mlx_info = malloc(sizeof(t_mlx));
	if (!mlx_info)
		return ;
	mlx_info->point_2d = point_2d;
	mlx_info->point_3d = point_3d;
	mlx_info->zoom_move = zoom_move;
	mlx_info->mlx_ptr = mlx_init();
	if (mlx_info->mlx_ptr == NULL)
	{
		write(2, "Failed to initialize the mlx\n", 30);
		exit (EXIT_FAILURE);
	}
	mlx_info->mlx_window_ptr = mlx_new_window
		(mlx_info->mlx_ptr, 3000, 1500, argv[1]);
	if (mlx_info->mlx_window_ptr == NULL)
	{
		write(2, "Failed to initialize the window\n", 33);
		exit (EXIT_FAILURE);
	}
	ft_draw_pixel_and_image(mlx_info, point_2d);
	ft_handle_mouse_and_keyboard(mlx_info);
}
