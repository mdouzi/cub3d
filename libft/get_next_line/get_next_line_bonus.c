/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:12:56 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 01:13:52 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	check_rest(char *rest)
{
	int	i;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*detect_new_line(char *line, char *buff, int fd, int *k)
{
	int		len;
	ssize_t	i;

	i = 1;
	while (i > 0)
	{
		len = 0;
		if (buff != NULL)
			line = ft_strjoin2(line, buff);
		while (line[len])
		{
			if (line[len] == '\n')
				break ;
			len++;
		}
		*k = len + 2;
		if (line[len] == '\n')
			break ;
		i = read(fd, buff, BUFFER_SIZE);
		if (i > 0)
			buff[i] = '\0';
		if (i < 0)
			break ;
	}
	return (line);
}

char	*get_rest_and_line(char *line, char *rest, int k)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_calloc2(k + 1, 1);
	while (line[i] != '\n' && line[i])
	{
		result[i] = line[i];
		i++;
	}
	result[i] = line[i];
	if (line[i])
		i++;
	k = 0;
	while (line[i])
	{
		rest[k] = line[i];
		i++;
		k++;
	}
	rest[k] = '\0';
	free (line);
	return (result);
}

char	*gnl(char *rest, char *buff, int fd)
{
	int		count;
	char	*line;

	line = NULL;
	count = 0;
	if (*rest)
		line = ft_strjoin2(line, rest);
	line = detect_new_line(line, buff, fd, &count);
	if (buff != NULL)
		free(buff);
	return (get_rest_and_line(line, rest, count));
}

char	*get_next_line(int fd)
{
	ssize_t		i;
	char		*buff;
	static char	rest[FOPEN_MAX][BUFFER_SIZE + 1];
	int			count;

	if (fd < 0)
		return (NULL);
	count = check_rest(rest[fd]);
	i = 1;
	if (!count)
	{
		buff = ft_calloc2(BUFFER_SIZE + 1, 1);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			ft_bzero2(rest[fd], BUFFER_SIZE);
	}
	else
		buff = NULL;
	if (i <= 0 && !(*rest[fd]))
	{
		free(buff);
		return (NULL);
	}
	return (gnl(rest[fd], buff, fd));
}
