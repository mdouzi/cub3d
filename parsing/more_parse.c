/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:07:54 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/17 22:33:09 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**convert_map(char *line)
{
	char	**str;

	str = ft_split(line, '\n');
	return (str);
}

int	play_char(char c, int *a)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		(*a)++;
		return (1);
	}
	else
		return (0);
}

void	get_len_wide(t_map *g)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	g->len = 0;
	g->wide = 0;
	while (g->mapo[j])
	{
		i = 0;
		while (g->mapo[j][i])
			i++;
		if (i > g->len)
			g->len = i;
		j++;
	}
	g->wide = j;
}
