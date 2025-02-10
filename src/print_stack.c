/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:47:21 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/16 17:46:12 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prints(t_stack *node)
{
	int	i;

	i = 1;
	while (node != NULL)
	{
		printf("\nnode : %i\n", i);
		printf("index %i\n", node->index);
		printf("numero %i\n", node->num);
		printf("max %i\n", node->max);
		printf("min %i\n", node->min);
		printf("cost %i\n", node->cost);
		printf("above median %i\n", node->abv_med);
		printf("cheapest %i\n", node->cheapest);
		printf("prev %p\n", node->prev);
		printf("now %p\n", node->direccion);
		printf("next %p\n", node->next);
		printf("target %p\n", node->target);
		node = node->next;
		i++;
	}
}
