/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:10:44 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:10 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_rotate(t_stack **start, t_stack **end, t_stack *cheapest, int flag)
{
	while (cheapest != *start && cheapest->target != *end)
		rr(start, end);
	while (cheapest != *start || cheapest->target != *end)
	{
		if (cheapest != *start)
		{
			if (flag == 0)
				ra(start);
			else if (flag == 1)
				rb(start);
		}
		if (cheapest->target != *end)
		{
			if (flag == 0)
				rb(end);
			else if (flag == 1)
				ra(end);
		}
	}
}

void	best_r_rotate(t_stack **start, t_stack **end, t_stack *cheapest,
		int flag)
{
	while (cheapest != *start && cheapest->target != *end)
		rrr(start, end);
	while (cheapest != *start || cheapest->target != *end)
	{
		if (cheapest != *start)
		{
			if (flag == 0)
				rra(start);
			else if (flag == 1)
				rrb(start);
		}
		if (cheapest->target != *end)
		{
			if (flag == 0)
				rrb(end);
			else if (flag == 1)
				rra(end);
		}
	}
}

void	placement_a(t_stack **start, t_stack **end, t_stack *cheapest)
{
	while (cheapest != *start)
	{
		if (cheapest->abv_med == 0)
			ra(start);
		if (cheapest->abv_med == 1)
			rra(start);
	}
	while (cheapest->target != *end)
	{
		if (cheapest->target->abv_med == 0)
			rb(end);
		if (cheapest->target->abv_med == 1)
			rrb(end);
	}
}

void	placement_b(t_stack **start, t_stack **end, t_stack *cheapest)
{
	while (cheapest != *start)
	{
		if (cheapest->abv_med == 0)
			rb(start);
		if (cheapest->abv_med == 1)
			rrb(start);
	}
	while (cheapest->target != *end)
	{
		if (cheapest->target->abv_med == 0)
			ra(end);
		if (cheapest->target->abv_med == 1)
			rra(end);
	}
}

void	push_smallest(t_stack **a)
{
	t_stack	*min;
	t_stack	*tmp;
	int		total;
	int		count;

	total = 1;
	count = 1;
	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
		total++;
	}
	tmp = *a;
	while (tmp->num != min->num)
	{
		count++;
		tmp = tmp->next;
	}
	go_top(a, min, total, count);
}
