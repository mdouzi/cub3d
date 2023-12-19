/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:08 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/14 01:50:59 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		ref;

	ref = 0;
	i = 0;
	if (*needle == '\0' || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		while (*haystack == *needle && *needle != '\0' && i++ < len)
		{
			ref++;
			needle++;
			haystack++;
		}
		if (*needle == '\0')
			return ((char *)haystack - ref);
		needle -= ref;
		haystack -= ref;
		i -= ref;
		ref = 0;
		haystack++;
		i++;
	}
	return (NULL);
}
