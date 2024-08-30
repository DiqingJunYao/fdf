/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:10:42 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 18:20:48 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_color(t_2d_point *first, t_2d_point *second, t_mlx *mlx_info)
{
	if (second->o_z > 0 || first->o_z > 0)
		draw_line(first, second, 0xFF0000, mlx_info);
	else if (second->o_z < 0 || first->o_z < 0)
		draw_line(first, second, 0x00FF00, mlx_info);
	else
		draw_line(first, second, 0xFFFFFF, mlx_info);
}

void	ft_link_right(t_mlx *mlx_info,
		t_2d_point *point_2d, t_2d_point *start_point)
{
	t_2d_point	*temp;

	temp = start_point;
	while (temp && (temp->o_x != (point_2d->o_x + 1)
			|| temp->o_y != point_2d->o_y))
		temp = temp->next;
	if (temp)
		ft_draw_color(point_2d, temp, mlx_info);
}

void	ft_link_down(t_mlx *mlx_info,
		t_2d_point *point_2d, t_2d_point *start_point)
{
	t_2d_point	*temp;

	temp = start_point;
	while (temp && (temp->o_x != point_2d->o_x
			|| temp->o_y != (point_2d->o_y + 1)))
		temp = temp->next;
	if (temp)
		ft_draw_color(point_2d, temp, mlx_info);
}

void	ft_put_pixel(t_mlx *mlx_info,
		t_2d_point *point_2d, t_2d_point *start_point)
{
	t_2d_point	*temp;

	temp = point_2d;
	while (temp)
	{
		ft_link_right(mlx_info, temp, start_point);
		ft_link_down(mlx_info, temp, start_point);
		temp = temp->next;
	}
}
