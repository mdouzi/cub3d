/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:58:53 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/22 23:44:39 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		i;
	int		len_s1;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = 0;
	len_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[len_s1 - i]) && i < len_s1)
		i++;
	copy = ft_substr(s1, 0, len_s1 - i + 1);
	return (copy);
}
