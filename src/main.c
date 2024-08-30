/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:04:10 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 19:39:35 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_3d_point	*point_3d;
	t_2d_point	*point_2d;
	t_zoom_move	*zoom_move;

	if (argc == 2)
	{
		point_3d = ft_read_and_fill(argv[1]);
		zoom_move = malloc(sizeof(t_zoom_move));
		if (!zoom_move)
			return (0);
		zoom_move->x = 0;
		zoom_move->y = 0;
		zoom_move->z = 30;
		zoom_move->angle_degree = 30;
		point_2d = ft_change_3d_to_2d(point_3d, zoom_move);
		ft_set_mlx(argv, point_2d, point_3d, zoom_move);
		ft_free_list_2d(point_2d);
		ft_free_list_3d(point_3d);
	}
	else
	{
		write(2, "error\n", 6);
		exit (EXIT_FAILURE);
	}
}
