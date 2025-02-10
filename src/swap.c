/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:47:38 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/17 13:51:40 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_2;

	if (stack && (*stack) && (*stack)->next)
	{
		tmp = (*stack)->next;
		tmp_2 = tmp->next;
		(*stack)->next = tmp_2;
		if (tmp_2)
			tmp_2->prev = *stack;
		(*stack)->prev = tmp;
		tmp->prev = NULL;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
