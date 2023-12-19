/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:37 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/13 10:34:39 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_val_b(t_window *win)
{
	win->player->speed = 0.6;
	win->player->v = assign_vect(win->player->speed, 0, win->player->angle);
	win->mlx_ptr = mlx_init(win->screen->x, win->screen->y,
			"Super Duper Cool 3D Game!!!", false);
	if (!win->mlx_ptr)
	{
		free_all(win);
		error();
	}
	win->img = mlx_new_image(win->mlx_ptr,
			win->screen->x, win->screen->y);
	if (!win->img)
	{
		free_all(win);
		error();
	}
	mlx_loop_hook(win->mlx_ptr, &keyhook_b, win);
	mlx_image_to_window(win->mlx_ptr, win->img, 0, 0);
	mlx_loop(win->mlx_ptr);
}

void	ft_start_b(t_map *g)
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
	init_val_b(win);
	free_all(win);
}

void	parser2_b(t_map *g)
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
	ft_start_b(g);
}

void	parser_b(t_map *g, int fd)
{
	int	i;

	i = 0;
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
	parser2_b(g);
}

int	main(int ac, char **av)
{
	t_map	*g;
	int		fd;

	check_lines(av[1]);
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd > -1)
	{
		g = ft_calloc(1, sizeof(t_map));
		parser_b(g, fd);
	}
	else
		ft_exit("Error need more information, Exiting...");
}
