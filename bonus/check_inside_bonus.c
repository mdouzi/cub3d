/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 05:51:51 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/18 05:51:52 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_inside_b(t_window *win, t_point player)
{
	int	i;
	int	j;

	i = (player.y + 1) / 10;
	j = (player.x + 1) / 10;
	if (win->map->mapo[i][j] == '1' || win->map->mapo[i][j] == ' '
			|| !win->map->mapo[i][j])
		return (0);
	i = (player.y - 5) / 10;
	j = (player.x - 5) / 10;
	if (win->map->mapo[i][j] == '1' || win->map->mapo[i][j] == ' '
			|| !win->map->mapo[i][j])
		return (0);
	i = (player.y - 2) / 10;
	j = (player.x - 2) / 10;
	if (win->map->mapo[i][j] == '1' || win->map->mapo[i][j] == ' '
			|| !win->map->mapo[i][j])
		return (0);
	return (1);
}
