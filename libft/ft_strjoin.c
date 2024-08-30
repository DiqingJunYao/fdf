/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:35:35 by dyao              #+#    #+#             */
/*   Updated: 2024/06/14 21:56:45 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(a * sizeof(char));
	if (!str)
		return (0);
	b = 0;
	while (s1[b])
	{
		str[b] = s1[b];
		b++;
	}
	b = 0;
	while (s2[b])
	{
		str[ft_strlen(s1) + b] = s2[b];
		b++;
	}
	str[a - 1] = '\0';
	return (str);
}
