/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:18 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:08 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_num(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		if (av[i][0] == '\0')
			return (1);
		if ((av[j][i]) == '-' || (av[j][i]) == '+')
			i++;
		if (!ft_isdigit(av[j][i]))
			return (1);
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
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
		if ((int)ft_atol(av[i]) > INT_MAX || (int)ft_atol(av[i]) < INT_MIN)
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
