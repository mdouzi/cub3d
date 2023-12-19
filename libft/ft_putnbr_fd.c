/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:46:30 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/23 01:34:10 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	nb_printer(int nb, int fd)
{
	char	printer;
	int		nb_reserve;
	int		nb_table[10];
	int		i;

	i = 0;
	printer = '0';
	nb_reserve = nb ;
	while (nb_reserve > 0)
	{
		nb_table[i] = nb_reserve % 10;
		nb_reserve = nb_reserve / 10;
		i++;
	}
	while (i > 0)
	{
		printer = '0';
		printer = printer + nb_table[i - 1];
		write(fd, &printer, 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		nb_printer((-1) * n, fd);
	}
	else
		nb_printer(n, fd);
}
