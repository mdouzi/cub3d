/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:10:38 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/18 01:13:26 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	prime_clore(char *color, char *num, int *i)
{
	int	j;
	int	prime;

	j = -1;
	while (color[*i] == ' ')
		(*i)++;
	if (!ft_isdigit(color[*i]))
		return (-2);
	while (color[*i] == '0')
		(*i)++;
	while (ft_isdigit(color[*i]) && ++j > -2)
		num[j] = color[(*i)++];
	if (color[*i] == ',' || !color[*i])
		(*i)++;
	else
		return (-3);
	prime = ft_atoi(num);
	if (ft_strlen(num) > 3 || prime < 0 || prime > 256)
		return (-1);
	ft_bzero(num, ft_strlen(num));
	return (prime);
}

int	get_color(char *color, int r, int g, int b)
{
	int		i;
	char	*num;

	i = -1;
	if (!color)
		return (0);
	while (color[++i])
	{
		if (color[i] == ',')
			r++;
	}
	if (r == 2)
	{
		i = 0;
		num = (char *)ft_calloc(1, sizeof(char));
		r = prime_clore(color, num, &i);
		g = prime_clore(color, num, &i);
		b = prime_clore(color, num, &i);
		free(num);
		if (r > -1 && g > -1 && b > -1)
			return (((r << 24) | (g << 16) | (b << 8) | 0xff));
	}
	ft_putstr_fd("Error : check the rgb please\n", 2);
	return (0);
}
