/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:32:21 by dyao              #+#    #+#             */
/*   Updated: 2024/06/15 20:15:47 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocate_and_fill(char *s, size_t i)
{
	char	*part;
	size_t	j;

	j = 0;
	part = (char *)malloc(i + 1);
	if (!part)
		return (NULL);
	while (j < i)
	{
		part[j] = s[j];
		j++;
	}
	part[j] = '\0';
	return (part);
}

static void	ft_free_memory(char **str, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	ft_the_main_split(char *s, char c, char **str)
{
	size_t	a;
	size_t	i;

	a = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		str[a] = ft_allocate_and_fill(s, i);
		if (!str[a])
		{
			ft_free_memory(str, a);
			return ;
		}
		s += i + (*s == c);
		a++;
	}
	str[a] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	char	*tgt;
	size_t	a;

	tgt = (char *) s;
	a = 0;
	while (*tgt)
	{
		if (*tgt != c && (tgt == s || *(tgt - 1) == c))
			a++;
		tgt++;
	}
	final = (char **)malloc((a + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	ft_the_main_split((char *)s, c, final);
	return (final);
}

/*int main(void)
{
    char *str = "Does this work?";
    char delimiter = ' ';
    char **result = ft_split(str, delimiter);
    size_t i = 0;

    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (result[i])
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return 0;
}*/
