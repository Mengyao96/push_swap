/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:23:27 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/31 13:11:04 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

static int	is_nbr(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long	str_to_int(char *str)
{
	size_t	i;
	int		sign;
	long	sum;

	i = 0;
	sign = 1;
	sum = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (is_nbr(str[i]) == 1)
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * sign);
}

long	ft_atoi_ps(char *str)
{
	size_t	i;
	long	nbr;

	if (!str || !*str)
		return (0);
	i = 0;
	if (is_space(str[i]))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	nbr = str_to_int(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (nbr);
}

// #include <string.h>
// #include <stdio.h>

// int	main (void)
// {
// 	int		nbr;
// 	char	*str = "++0";

// 	nbr = ft_atoi(str);
// 	printf("%d", nbr);
// 	return (nbr);
// }
