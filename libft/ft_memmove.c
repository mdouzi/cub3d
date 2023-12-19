/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:18 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/23 01:21:35 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_src;
	char	*p_dst;

	i = 0;
	if (!dst && !src)
		return (NULL);
	p_src = (char *)src + len - 1;
	p_dst = (char *)dst + len - 1;
	if (p_dst > p_src)
	{
		while (i < len)
		{
			*p_dst = *p_src;
			p_dst--;
			p_src--;
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
