/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:39:16 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/18 00:13:41 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_start(t_map *g)
{
	if (g->ea)
		free(g->ea);
	if (g->so)
		free(g->so);
	if (g->no)
		free(g->no);
	if (g->we)
		free(g->we);
	if (g->c)
		free(g->c);
	if (g->f)
		free(g->f);
}

void	init_data(t_window *win, t_map *g)
{
	win->screen = (t_cord *)ft_calloc(1, sizeof(t_cord));
	win->screen->x = 1280;
	win->screen->y = 720;
	win->player = g->player;
	win->map = g;
	win->t.ea = mlx_load_png(g->ea);
	win->t.so = mlx_load_png(g->so);
	win->t.no = mlx_load_png(g->no);
	win->t.we = mlx_load_png(g->we);
	win->t.ceileng = get_color(g->c, 0, 0, 0);
	win->t.floor = get_color(g->f, 0, 0, 0);
}

void	ft_start(t_map *g)
{
	t_window	*win;
	int			j;

	win = (t_window *)ft_calloc(1, sizeof(t_window));
	init_data(win, g);
	free_start(win->map);
	j = -1;
	while (g->full_file[++j])
		free(g->full_file[j]);
	free(g->full_file);
	exit_from_start(win);
	if (!win->t.ea || !win->t.so || !win->t.we || !win->t.no || !win->t.ceileng
		|| !win->t.floor)
	{
		free_all(win);
		exit(1);
	}
	init_val(win);
	free_all(win);
}

void	parser2(t_map *g)
{
	int	i;

	i = 0;
	get_len_wide(g);
	check_borders_line(g);
	check_borders_col(g);
	if (check_map_line(g->mapo) == 1)
		exit_all(g, "error invalid map\n");
	else if (check_map_line(g->mapo) == 2)
		exit_all(g, "error more than 1 player or player not found\n");
	if (get_text(g))
		free_txt(g, "error need more info\n");
	g->player = get_player_location(g->player, g, &i);
	ft_start(g);
}

void	parser(t_map *g, int fd)
{
	g->player = ft_calloc(1, sizeof(t_player));
	if (get_data(fd, g) > 0)
	{
		free(g->split_line);
		if (g->map_start)
			free(g->map_line);
		ft_putstr_fd("error: invalid map\n", 2);
		exit(1);
	}
	if (get_map(fd, g) < 3)
	{
		free(g->split_line);
		free(g->map_line);
		ft_putstr_fd("error: invalid map\n", 2);
		exit(1);
	}
	g->mapo = convert_map(g->map_line);
	g->full_file = convert_map(g->split_line);
	free(g->split_line);
	free(g->map_line);
	parser2(g);
}
