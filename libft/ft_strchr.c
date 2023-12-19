/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:36:54 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/08 19:39:09 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
		{
			i = 1;
			break ;
		}
		ptr++;
	}
	if ('\0' == c)
		i = 1;
	if (i == 1)
		return (ptr);
	else
		return (NULL);
}
