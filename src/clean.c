/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:30:21 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/07 16:06:25 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->max = 0;
		tmp->min = 0;
		tmp->cost = 0;
		tmp->abv_med = 0;
		tmp->cheapest = 0;
		tmp->target = NULL;
		tmp = tmp->next;
	}
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
