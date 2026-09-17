/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:32:25 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/11 14:25:27 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static char	**fill_tab(char **split, char const *s, char c);
static void	free_all(char **split, int j);

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		count;

	if (!s)
		return (NULL);
	i = 0;
	count = count_words(s, c) + 1;
	split = malloc(count * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_tab(split, s, c);
	return (split);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**fill_tab(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
		{
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
				return (free_all(split, j), NULL);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

static void	free_all(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
}
