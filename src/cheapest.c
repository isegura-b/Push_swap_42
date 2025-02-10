/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:19:56 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:41:14 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_median(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		if (i > (ft_lstsize(*stack) / 2))
			tmp->abv_med = 1;
		else
			tmp->abv_med = 0;
		i++;
		tmp = tmp->next;
	}
}

void	ft_cost(t_stack **start, t_stack **end)
{
	int		len_start;
	int		len_end;
	t_stack	*tmp;

	tmp = *start;
	len_start = ft_lstsize(*start);
	len_end = ft_lstsize(*end);
	while (tmp->next)
	{
		if (tmp->abv_med == 1)
			tmp->cost += len_start - (tmp->index);
		if (tmp->abv_med == 0)
			tmp->cost += (tmp->index);
		if (tmp->target->abv_med == 1)
			tmp->cost += len_end - (tmp->target->index);
		if (tmp->target->abv_med == 0)
			tmp->cost += (tmp->target->index);
		tmp = tmp->next;
	}
}

void	ft_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	int		cheaper;
	t_stack	*cheapest;

	tmp = *stack;
	cheaper = INT_MAX;
	cheapest = tmp;
	while (tmp->next)
	{
		if (tmp->cost < cheaper)
		{
			cheaper = tmp->cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapest)
		cheapest->cheapest = 1;
}

void	best_mv_a(t_stack **start, t_stack **end)
{
	t_stack	*tmp;

	ft_cheapest(start);
	tmp = *start;
	move_a(start, end, tmp);
}

void	best_mv_b(t_stack **start, t_stack **end)
{
	t_stack	*tmp;

	ft_cheapest(start);
	tmp = *start;
	move_b(start, end, tmp);
}
