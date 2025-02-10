/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:32:23 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/16 14:53:20 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_small_sort(t_stack **a, int ac)
{
	if (ac == 3)
		sa(a);
	if (ac == 4)
		ft_sort_3(a);
}

void	ft_sort_3(t_stack **a)
{
	ft_lim_s(a);
	ft_lim_b(a);
	if ((*a)->max == 1)
		ra(a);
	else if ((*a)->next->max == 1)
		rra(a);
	if ((*a)->next->min == 1)
		sa(a);
}
