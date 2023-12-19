/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:31:59 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/14 01:45:41 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*uni;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (NULL);
	uni = (char *)ft_calloc(ft_strlen (s1) + ft_strlen (s2) + 1, 1);
	if (!uni)
		return (NULL);
	while (s1[++i])
		uni[i] = s1[i];
	while (s2[++j])
		uni[i + j] = s2[j];
	return (uni);
}
