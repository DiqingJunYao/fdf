/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_fill_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:09:47 by dyao              #+#    #+#             */
/*   Updated: 2024/08/13 20:10:10 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_point	*ft_read_and_fill(char *file_name)
{
	int			fd;
	t_3d_point	*point_3d;
	t_3d_point	*temp;

	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		write(2, "The file DO NOT exist!\n", 24);
		exit(EXIT_FAILURE);
	}
	point_3d = initialize_points(fd);
	point_3d = link_points(fd, point_3d);
	temp = point_3d;
	while (temp)
	{
		if (temp->z == INT_MAX)
		{
			ft_free_list_3d(point_3d);
			exit(EXIT_FAILURE);
		}
		temp = temp->next;
	}
	return (point_3d);
}
