/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:01 by dyao              #+#    #+#             */
/*   Updated: 2024/08/14 13:38:32 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3d_point	*ft_creat_point(void)
{
	t_3d_point	*a;

	a = (t_3d_point *)malloc(sizeof(t_3d_point));
	if (!a)
	{
		write(2, "memory allocation failed!", 26);
		exit (EXIT_FAILURE);
	}
	a->next = NULL;
	a->x = 0;
	a->y = 0;
	a->z = 0;
	return (a);
}

static void	ft_check_nbr_and_fill(t_3d_point *a, char *temp, int j, int i)
{
	int	index;

	index = 0;
	if (temp[index] == '\n')
		return ;
	while (temp[index])
	{
		if ((temp[index] >= '0' && temp[index] <= '9')
			|| temp[index] == '\n' || temp[index] == '-')
			index++;
		else
		{
			write(2, "error\n", 6);
			break ;
		}
	}
	a->y = i;
	a->x = j;
	if (temp[index] != '\0')
		a->z = INT_MAX;
	else
	{
		index = ft_atoi(temp);
		a->z = index;
	}
}

static t_3d_point	*ft_creat_and_fill(char **temp_store)
{
	int			j;
	static int	i;
	t_3d_point	*a;
	t_3d_point	*b;
	t_3d_point	*temp;

	j = 0;
	a = ft_creat_point();
	ft_check_nbr_and_fill(a, temp_store[j], j, i);
	j++;
	temp = a;
	while (temp_store[j])
	{
		b = a;
		a = ft_creat_point();
		ft_check_nbr_and_fill(a, temp_store[j], j, i);
		b->next = a;
		j++;
	}
	a->next = NULL;
	i++;
	ft_free_double_pointer(temp_store);
	return (temp);
}

t_3d_point	*initialize_points(int fd)
{
	char				*temp_str;
	char				**temp_store;
	t_3d_point			*point;

	temp_str = get_next_line(fd);
	temp_store = ft_split(temp_str, ' ');
	point = ft_creat_and_fill(temp_store);
	free(temp_str);
	return (point);
}

t_3d_point	*link_points(int fd, t_3d_point *point)
{
	char				*temp_str;
	char				**temp_store;
	t_3d_point			*new_point;
	static t_3d_point	*temp;
	t_3d_point			*hold;

	hold = point;
	temp = point;
	while (temp->next)
		temp = temp->next;
	temp_str = get_next_line(fd);
	while (temp_str != NULL)
	{
		temp_store = ft_split(temp_str, ' ');
		new_point = ft_creat_and_fill(temp_store);
		temp->next = new_point;
		temp = new_point;
		while (temp->next != NULL)
			temp = temp->next;
		free(temp_str);
		temp_str = get_next_line(fd);
	}
	return (hold);
}
