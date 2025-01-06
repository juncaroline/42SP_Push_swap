/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:16:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/06 12:32:24 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_word_l(char const *s, char c, int i)
{
	int		word_len;

	word_len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word_len++;
		i++;
	}
	return (word_len);
}

static void	ft_free(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

static int	fill_words(char **parse_words, char const *s, char c, int count)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		word_len = ft_word_l(s, c, i);
		parse_words[j] = ft_substr(s, i, word_len);
		if (parse_words[j] == NULL)
		{
			ft_free(parse_words, j);
			return (0);
		}
		i = i + word_len;
		j++;
	}
	parse_words[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**parse_words;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_wcount(s, c);
	parse_words = (char **)malloc((count + 1) * sizeof(char *));
	if (parse_words == NULL)
		return (NULL);
	if (!fill_words(parse_words, s, c, count))
		return (NULL);
	return (parse_words);
}
