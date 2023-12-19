/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:57:47 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/23 01:25:02 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = (char *)ft_calloc(len + 1, 1);
	if (!sub)
	{
		return (NULL);
	}
	if (len == 0 || start >= (unsigned int)ft_strlen(s))
		return (sub);
	s += start;
	while (i < len)
	{
		sub[i] = s[i];
		i++;
	}
	return (sub);
}
