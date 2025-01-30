/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:14:58 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:11:06 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a(t_stack **a, t_stack **b)
{
	int		closer;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*closest;

	tmp_a = *a;
	while (tmp_a)
	{
		tmp_b = *b;
		closest = *b;
		closer = INT_MIN;
		while (tmp_b)
		{
			if (tmp_a->num > tmp_b->num && tmp_b->num > closer)
			{
				closer = tmp_b->num;
				closest = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closer == INT_MIN)
			closest = find_biggest(b);
		tmp_a->target = closest;
		tmp_a = tmp_a->next;
	}
}

void	target_b(t_stack **b, t_stack **a)
{
	int		closer;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*closest;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		closest = *a;
		closer = INT_MAX;
		while (tmp_a)
		{
			if (tmp_b->num < tmp_a->num && tmp_a->num < closer)
			{
				closer = tmp_a->num;
				closest = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closer == INT_MAX)
			closest = find_smallest(a);
		tmp_b->target = closest;
		tmp_b = tmp_b->next;
	}
}

void	ft_index(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = *b;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	ft_algorithm_sort(t_stack **a, t_stack **b, int flag)
{
	pb(a, b);
	if (flag == 1)
		pb(b, a);
	while (ft_lstsize(*a) > 3)
	{
		target_a(a, b);
		ft_index(a, b);
		above_median(a);
		above_median(b);
		ft_cost(a, b);
		best_mv_a(a, b);
		clean(a);
	}
	ft_sort_3(a);
	while (*b)
	{
		target_b(b, a);
		ft_index(a, b);
		above_median(a);
		above_median(b);
		ft_cost(b, a);
		best_mv_b(b, a);
		clean(b);
	}
	push_smallest(a);
}
