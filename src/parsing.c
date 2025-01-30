/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:18 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/16 17:46:59 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i]) == '-' || (av[j][i]) == '+')
			{
				if (av[j][i + 1] < '0' || av[j][i + 1] > '9')
					return (1);
				i++;
			}
			if (av[j][i] < '0' || av[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

long	ft_atol(char *av)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (((av[i] >= 9 && av[i] <= 13) || av[i] == 32) && av[i])
		i++;
	if (av[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (av[i] == '+')
		i++;
	while ((av[i] >= '0' && av[i] <= '9') && av[i])
	{
		n = n * 10 + (av[i] - '0');
		i++;
	}
	return (n * sign);
}

int	is_dup(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 1;
		while (av[j + i])
		{
			if (ft_atol(av[j]) == ft_atol(av[j + i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	int_error(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((int)ft_atol(av[i]) >= INT_MAX || (int)ft_atol(av[i]) <= INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_parsing(char **av)
{
	if (is_num(av) || is_dup(av) || int_error(av))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
