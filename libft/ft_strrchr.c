/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:38:04 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/08 19:41:55 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = len + 1;
	ptr = (char *)str + len;
	while (i > 0)
	{
		if (*ptr == (char)c)
			break ;
		i--;
		ptr--;
	}
	if (i == 0)
		return (NULL);
	return (ptr);
}
