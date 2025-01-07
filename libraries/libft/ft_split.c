/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:16:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/07 09:18:03 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_scount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_memsst(char const *s, size_t i, size_t j)
{
	char	*sst;
	size_t	n;

	sst = (char *)malloc(sizeof(char) * (i - j + 1));
	if (sst == NULL)
		return (NULL);
	n = 0;
	while (j < i)
	{
		sst[n] = s[j];
		n++;
		j++;
	}
	sst[n] = '\0';
	return (sst);
}

static void	ft_free_all(char **memalloc, size_t k)
{
	if (memalloc == NULL)
		return ;
	while (k > 0)
	{
		k--;
		free(memalloc[k]);
	}
	free(memalloc);
}

static int	ft_fill_words(char **memalloc, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
		{
			memalloc[k] = ft_memsst(s, i, j);
			if (memalloc[k] == NULL)
				return (ft_free_all(memalloc, k), 0);
			k++;
		}
	}
	memalloc[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**memalloc;

	if (!s)
		return (NULL);
	memalloc = (char **)malloc(sizeof(char *) * (ft_scount(s, c) + 1));
	if (memalloc == NULL)
		return (NULL);
	if (!ft_fill_words(memalloc, s, c))
	{
		ft_free_all(memalloc, ft_scount(s, c));
		return (NULL);
	}
	return (memalloc);
}
