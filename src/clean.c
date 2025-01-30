/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:30:21 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/19 20:56:38 by isegura-         ###   ########.fr       */
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
