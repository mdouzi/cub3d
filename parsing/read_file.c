/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 03:39:59 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/17 22:05:58 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	read_data_lines(int fd, t_map *g, int *i)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && *i > 0)
	{
		if (ft_isalpha(line[0]))
		{
			get_last_n_line(line, &g->split_line);
			(*i)--;
		}
		if (ft_isdigit(line[0]))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (line[0] == '\0')
		free(line);
	else
	{
		g->map_line = ft_strdup("");
		g->map_start = 1;
		get_last_n_line(line, &g->map_line);
		free(line);
	}
	return (0);
}

int	get_data(int fd, t_map *g)
{
	int	i;

	i = 6;
	g->split_line = ft_strdup("");
	read_data_lines(fd, g, &i);
	return (i);
}

int	read_map_line(int fd, t_map *g, int *line_count)
{
	char	*line;

	if (g->map_start != 1)
		g->map_line = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		get_last_n_line(line, &g->map_line);
		(*line_count)++;
	}
	free(line);
	return (0);
}

int	process_map_lines(int fd, t_map *g, int *line_count)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		(*line_count)++;
		if (line[0] != '\0' && line[1] != '\0')
			get_last_n_line(line, &g->map_line);
		if (line[0] == '\n')
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	get_map(int fd, t_map *g)
{
	int	l;

	l = 1;
	read_map_line(fd, g, &l);
	process_map_lines(fd, g, &l);
	close(fd);
	return (l);
}
