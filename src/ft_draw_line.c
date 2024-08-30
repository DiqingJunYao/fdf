/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:46:09 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 19:40:25 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_point	*ft_copy_point(t_2d_point *point)
{
	t_2d_point	*temp;

	temp = malloc(sizeof(t_2d_point));
	temp->next = point->next;
	temp->o_x = point->o_x;
	temp->o_y = point->o_y;
	temp->x = point->x;
	temp->y = point->y;
	return (temp);
}

t_draw_line	*ft_init_every_data(t_2d_point *start, t_2d_point *end)
{
	t_draw_line	*temp;

	temp = malloc(sizeof(t_draw_line));
	if (!temp)
		return (NULL);
	temp->dx = abs((int)end->x - (int)start->x);
	temp->dy = abs((int)end->y - (int)start->y);
	if ((int)start->x < (int)end->x)
		temp->sx = 1;
	else
		temp->sx = -1;
	if ((int)start->y < (int)end->y)
		temp->sy = 1;
	else
		temp->sy = -1;
	temp->err = temp->dx - temp->dy;
	return (temp);
}

void	draw_pixel(int x, int y, int color, t_mlx *mlx_info)
{
	int	offset;

	offset = (y * mlx_info->size_line) + (x * (mlx_info->bits_per_pixel / 8));
	*(unsigned int *)(mlx_info->data_addr + offset) = color;
}

void	ft_free_draw_line(t_draw_line *temp, t_2d_point *start, t_2d_point *end)
{
	free (temp);
	free (start);
	free (end);
}

void	draw_line(t_2d_point *point1, t_2d_point *point2,
		int color, t_mlx *mlx_info)
{
	t_draw_line	*temp;
	t_2d_point	*start;
	t_2d_point	*end;

	start = ft_copy_point(point1);
	end = ft_copy_point(point2);
	temp = ft_init_every_data(start, end);
	while (1 && ft_check_pixel(start) != 1)
	{
		draw_pixel((int)start->x, (int)start->y, color, mlx_info);
		if ((int)start->x >= (int)end->x && (int)start->y >= (int)end->y)
			break ;
		temp->e2 = temp->err * 2;
		if (temp->e2 > -temp->dy)
		{
			temp->err -= temp->dy;
			start->x += temp->sx;
		}
		if (temp->e2 < temp->dx)
		{
			temp->err += temp->dx;
			start->y += temp->sy;
		}
	}
	ft_free_draw_line(temp, start, end);
}
