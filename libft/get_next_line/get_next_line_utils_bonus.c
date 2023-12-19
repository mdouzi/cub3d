/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:39:25 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 19:39:34 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strchr2(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if ('\0' == c)
		i = 1;
	if (i == 1)
		return (1);
	else
		return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*uni;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_calloc2(1, 1);
		*s1 = '\0';
	}
	i = -1;
	j = -1;
	uni = (char *)ft_calloc2(ft_strlen2(s1) + ft_strlen2(s2) + 1, 1);
	if (!uni)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		uni[i] = s1[i];
	while (s2[++j])
		uni[i + j] = s2[j];
	free(s1);
	return (uni);
}

int	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero2(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

void	*ft_calloc2(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero2(p, count * size);
	return (p);
}
