/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:01:16 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 19:38:35 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *str1 )
{
	char	*str2;
	size_t	a;
	size_t	b;

	a = ft_strlen(str1);
	str2 = (char *)malloc((a + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	b = 0;
	while (str1[b])
	{
		str2[b] = str1[b];
		b++;
	}
	str2[b] = '\0';
	return (str2);
}
