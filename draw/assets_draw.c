/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:37:09 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/09 00:37:12 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cub_drawer(t_window *win, t_point start, t_point end, int color)
{
	int	y;
	int	x;

	x = start.x;
	y = start.y;
	while (x < end.x)
	{
		y = start.y;
		while (y < end.y)
		{
			if (x > win->screen->x && y > win->screen->y
				&& x < 0 && y < 0)
				return ;
			mlx_put_pixel(win->img, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_background(t_window *win, int floor, int ceiling)
{
	t_point	start;
	t_point	end;

	start = assign_int_point(0, 0);
	end = assign_int_point(win->screen->x, win->screen->y / 2);
	cub_drawer(win, start, end, floor);
	start = assign_int_point(0, win->screen->y / 2 - 1);
	end = assign_int_point(win->screen->x, win->screen->y);
	cub_drawer(win, start, end, ceiling);
}
