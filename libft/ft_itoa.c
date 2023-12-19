/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:12:47 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/08 20:17:37 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	number_len(int n)
{
	int		number;
	int		digit;

	number = n;
	digit = 1;
	if (number == -2147483648)
	{
		digit = 11;
		return (digit);
	}
	if (number < 0)
		number = number * (-1);
	while (number > 9)
	{
		number = number / 10;
		digit++;
	}
	if (n < 0)
		digit++;
	return (digit);
}

static void	chek_particulare_case(int n, char *p_str)
{
	char	*max;
	int		i;

	max = "-2147483648";
	i = 0;
	if (n == -2147483648)
	{
		while (i < 12)
		{
			p_str[i] = max[i];
			i++;
		}
	}
	else if (n == 0)
		p_str[0] = '0';
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;
	int		i;

	i = 1;
	digit = number_len(n);
	str = (char *)malloc(digit + 1);
	if (!str)
		return (NULL);
	chek_particulare_case(n, str);
	if (n < 0)
		str[0] = '-';
	n = n * (-1) * (n < 0) + n * (n > 0);
	while (n > 0)
	{
		str[digit - i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	str[digit] = '\0';
	return (str);
}
