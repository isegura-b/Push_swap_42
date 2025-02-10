/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:46:03 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/17 11:59:09 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **end, t_stack **start)
{
	t_stack	*tmp;

	tmp = *start;
	*start = (*start)->next;
	if (*start)
		(*start)->prev = NULL;
	if (!*end)
	{
		*end = tmp;
		(*end)->next = NULL;
	}
	else
	{
		(*end)->prev = tmp;
		tmp->next = *end;
		*end = tmp;
	}
	tmp->prev = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		push(a, b);
		write (1, "pa\n", 3);
	}
}

void	pb(t_stack **b, t_stack **a)
{
	if (*a)
	{
		push(b, a);
		write (1, "pb\n", 3);
	}
}
