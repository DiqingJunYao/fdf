/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:55:07 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 23:31:09 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_place(char *src, char *set)
{
	size_t	start;
	size_t	a;
	size_t	b;

	if (!src)
		return (0);
	start = 0;
	a = 0;
	b = 0;
	while (set[b] && src[a])
	{
		if (src[a] == set[b])
		{
			b = 0;
			start++;
			a++;
		}
		else
			b++;
	}
	if (src[a] == '\0')
		return (a);
	return (start);
}

static size_t	ft_end_place(char *src, char *set)
{
	size_t	end;
	size_t	a;
	size_t	b;

	if (!src)
		return (0);
	end = ft_strlen(src) - 1;
	a = ft_strlen(src);
	b = 0;
	while (set[b] != '\0' && a > 0)
	{
		if (src[a - 1] == set[b])
		{
			b = 0;
			end--;
			a--;
		}
		else
			b++;
	}
	if (a == 0)
		return (a);
	return (end);
}

char	*copy_trimmed_string(char *rzt, char *tgt, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		rzt[i] = tgt[start];
		i++;
		start++;
	}
	rzt[i] = '\0';
	return (rzt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tgt;
	char	*rzt;

	tgt = (char *)s1;
	start = ft_start_place(tgt, (char *)set);
	end = ft_end_place(tgt, (char *)set);
	if (end < start || !s1 || *s1 == '\0')
		rzt = ft_calloc(1, sizeof(char));
	else
	{
		rzt = (char *) malloc (end - start + 2);
		if (!rzt)
			return (NULL);
		ft_bzero(rzt, end - start + 2);
		rzt = copy_trimmed_string(rzt, tgt, start, end);
	}
	return (rzt);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;
// 	char *res;
// 	a = "babababacbabccacccb cccbccccacccacccb cccbbbaacccaaabbabababab";
// 	b = "ab";
// 	res = ft_strtrim(".teste, bla ,.,.", ",.");
// 	printf("%s", ft_strtrim(a, b));
// }
