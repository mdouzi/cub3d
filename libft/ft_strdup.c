/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:20:23 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/14 01:35:57 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;

	len = ft_strlen(s1);
	copy = (char *)ft_calloc((len + 1), sizeof(char));
	if (!copy)
		return (NULL);
	while (*s1)
	{
		*copy = *s1;
		copy++;
		s1++;
	}
	copy -= len;
	return (copy);
}
