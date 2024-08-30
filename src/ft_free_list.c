/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:52:32 by dyao              #+#    #+#             */
/*   Updated: 2024/08/12 17:52:00 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_list_3d(t_3d_point *point)
{
	t_3d_point	*temp;

	while (point)
	{
		temp = point->next;
		free (point);
		point = temp;
	}
}

void	ft_free_list_2d(t_2d_point *point)
{
	t_2d_point	*temp;

	while (point)
	{
		temp = point->next;
		free (point);
		point = temp;
	}
}

void	ft_free_double_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free (pointer[i]);
		i++;
	}
	free (pointer);
}
