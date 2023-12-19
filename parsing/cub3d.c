/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:12:43 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/17 22:11:48 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_map	*g;
	int		fd;

	check_lines(av[1]);
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd > -1)
	{
		g = ft_calloc(1, sizeof(t_map));
		parser(g, fd);
	}
	else
		ft_exit("Error need more information, Exiting...");
}
