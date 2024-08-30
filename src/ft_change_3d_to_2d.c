/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_3d_to_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:09:30 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 18:20:32 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_convert_3d_to_2d(t_2d_point *point_2d,
			t_3d_point *point_3d, t_zoom_move *zoom_move)
{
	zoom_move->angle_radians = zoom_move->angle_degree * M_PI / 180;
	point_2d->x = (cos(zoom_move->angle_radians) * point_3d->x
			- cos(zoom_move->angle_radians) * point_3d->y)
		* zoom_move->z + 1500 + zoom_move->x;
	point_2d->y = (point_3d->x * sin(zoom_move->angle_radians)
			- point_3d->y * -sin(zoom_move->angle_radians)
			+ point_3d->z / 10 * cos(M_PI - zoom_move->angle_radians))
		* zoom_move->z + 200 + zoom_move->y;
	point_2d->o_x = point_3d->x;
	point_2d->o_y = point_3d->y;
	point_2d->o_z = point_3d->z;
}

void	ft_convert_3d_to_2d_v2(t_2d_point *point_2d,
			t_3d_point *point_3d, t_zoom_move *zoom_move)
{
	zoom_move->angle_radians = zoom_move->angle_degree * M_PI / 180;
	point_2d->x = (cos(zoom_move->angle_radians) * point_3d->x
			- cos(zoom_move->angle_radians) * point_3d->y
			+ point_3d->z / 10 * cos(M_PI - zoom_move->angle_radians * 2))
		* zoom_move->z + 1500 + zoom_move->x;
	point_2d->y = (point_3d->x * sin(zoom_move->angle_radians)
			- point_3d->y * -sin(zoom_move->angle_radians))
		* zoom_move->z + 200 + zoom_move->y;
	point_2d->o_x = point_3d->x;
	point_2d->o_y = point_3d->y;
	point_2d->o_z = point_3d->z;
}

static t_2d_point	*ft_creat_point(void)
{
	t_2d_point	*a;

	a = (t_2d_point *)malloc(sizeof(t_2d_point));
	if (!a)
	{
		write(2, "memory allocation failed!", 26);
		exit (EXIT_FAILURE);
	}
	a->next = NULL;
	a->x = 0;
	a->y = 0;
	a->o_x = 0;
	a->o_y = 0;
	a->o_z = 0;
	return (a);
}

static t_2d_point	*ft_creat_and_fill(
		t_3d_point *point_3d, t_zoom_move *zoom_move)
{
	t_2d_point	*a;
	t_2d_point	*b;
	t_2d_point	*temp;

	a = ft_creat_point();
	if (zoom_move->angle_degree <= 45 && zoom_move->angle_degree >= -45)
		ft_convert_3d_to_2d(a, point_3d, zoom_move);
	else
		ft_convert_3d_to_2d_v2(a, point_3d, zoom_move);
	point_3d = point_3d->next;
	temp = a;
	while (point_3d)
	{
		b = a;
		a = ft_creat_point();
		if (zoom_move->angle_degree <= 45 && zoom_move->angle_degree >= -45)
			ft_convert_3d_to_2d(a, point_3d, zoom_move);
		else
			ft_convert_3d_to_2d_v2(a, point_3d, zoom_move);
		b->next = a;
		point_3d = point_3d->next;
	}
	a->next = NULL;
	return (temp);
}

t_2d_point	*ft_change_3d_to_2d(t_3d_point *point_3d, t_zoom_move *zoom_move)
{
	t_2d_point	*point_2d;

	point_2d = ft_creat_and_fill(point_3d, zoom_move);
	return (point_2d);
}
