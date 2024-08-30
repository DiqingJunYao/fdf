/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:52 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 21:22:19 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str1;

	c = (char)c;
	str1 = NULL;
	while (*str)
	{
		if (*str == c)
			str1 = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		str1 = (char *)str;
	return (str1);
}

//THIS FUNCTION MUST INCLUDE <stddef.h>
//BECAUSE OF USING "NULL" IN THE FUNCTION.
/*#include <stdio.h>
int	main()
{
 	char	str[] = "Onde esta o W? Ca esta ele";
 	char	c = 'b';
 	printf("%s", ft_strrchr(str, c));
}*/
