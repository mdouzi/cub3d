/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:54:31 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/23 01:31:57 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	part_count(char *s, char c)
{
	int		part;

	part = 0;
	while (*s)
	{
		s++;
		if ((*s == c && *(s - 1) != c) || (*s == '\0' && *(s - 1) != c))
			part++;
	}
	return (part);
}

static int	*word_len(char *s, char c, int part)
{
	int		*array;
	int		i;

	array = (int *)malloc(part * sizeof(int));
	i = 0;
	while (*s)
	{
		array[i] = 1;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			array[i]++;
			s++;
		}
		if (!*s || i >= part - 1)
			break ;
		i++;
	}
	return (array);
}

static char	**word_cutter(char *s, char c, char **array)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c)
		{
			array[i][j] = s[k];
			j++;
			if (s[k + 1] == c)
			{
				i++;
				j = 0;
			}
		}
		k++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		*len_array;
	int		part;

	i = 0;
	if (!s)
		return (NULL);
	part = part_count((char *)s, c);
	array = (char **)malloc((part + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (part == 0)
		len_array = NULL;
	else
		len_array = word_len((char *)s, c, part);
	while (i < part)
	{
		array[i] = (char *)ft_calloc(len_array[i], sizeof(char));
		i++;
	}
	array = word_cutter((char *)s, c, array);
	array[i] = NULL;
	free(len_array);
	return (array);
}
