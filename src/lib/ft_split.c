/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:07:51 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/28 20:38:34 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			i++;
		}
		while (s[i] && s[i] == c)
		{
			i++;
		}
		count++;
	}
	return (count);
}

static char	*get_word(char const*s, char c)
{
	int		i;
	int		size;
	char	*word;

	size = 0;
	while (s[size] && s[size] != c)
	{
		size++;
	}
	word = malloc((size + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	word[size] = 0;
	i = 0;
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static char	**free_words(char **words)
{
	int	j;

	j = 0;
	while (words[j])
	{
		free(words[j]);
		j++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	words = ft_calloc((count_words(s + i, c) + 1), sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (s[i])
	{
		words[j] = get_word(s + i, c);
		if (words[j] == NULL)
			return (free_words(words));
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		j++;
	}
	return (words);
}
