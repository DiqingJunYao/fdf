/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:23:10 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 22:32:06 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_memory(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	b;
	char	*store;

	if (!s)
		return (0);
	a = start;
	b = ft_strlen(s);
	if (a >= b)
	{
		store = malloc(1 * sizeof(char));
		if (!store)
			return (NULL);
		*store = '\0';
		return (store);
	}
	if (b - start < len)
		len = b - start;
	store = malloc((len + 1) * sizeof(*s));
	if (!store)
		return (0);
	ft_bzero(store, len + 1);
	return (store);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	c;
	char	*store;

	store = allocate_memory(s, start, len);
	if (!store)
		return (0);
	if (start >= ft_strlen(s))
		return (store);
	c = 0;
	a = start;
	b = ft_strlen(s);
	if (b - start < len)
		len = b - start;
	while (c < len && s[a] != '\0')
	{
		store[c] = s[a];
		c++;
		a++;
	}
	store[c] = '\0';
	return (store);
}
