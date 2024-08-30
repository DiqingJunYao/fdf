/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:23 by dyao              #+#    #+#             */
/*   Updated: 2024/06/14 17:51:16 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char )(str1[i]) - (unsigned char )(str2[i]));
}

//don't forget to add the lib <stddef.h>
//size_t to avoid the problem of over the max of int.