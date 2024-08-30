/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:13:00 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 22:53:00 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str1;

	c = (char)c;
	str1 = (char *)str;
	while (*str1)
	{
		if (*str1 == c)
			return (str1);
		str1++;
	}
	if (c == '\0')
		return (str1);
	return (NULL);
}
