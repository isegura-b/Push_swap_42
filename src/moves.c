/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:34 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:41:16 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a(t_stack **start, t_stack **end, t_stack *tmp)
{
	while (tmp)
	{
		if (((tmp->abv_med) == 0) && ((tmp->target->abv_med) == 0)
			&& tmp->cheapest == 1)
		{
			best_rotate(start, end, tmp, 0);
			pb(end, start);
			break ;
		}
		else if (((tmp->abv_med == 1)) && ((tmp->target->abv_med == 1))
			&& tmp->cheapest == 1)
		{
			best_r_rotate(start, end, tmp, 0);
			pb(end, start);
			break ;
		}
		else if (((tmp->abv_med) != (tmp->target->abv_med))
			&& tmp->cheapest == 1)
		{
			placement_a(start, end, tmp);
			pb(end, start);
			break ;
		}
		tmp = tmp->next;
	}
}

void	move_b(t_stack **start, t_stack **end, t_stack *tmp)
{
	while (tmp)
	{
		if (((tmp->abv_med) == 0) && ((tmp->target->abv_med) == 0)
			&& tmp->cheapest == 1)
		{
			best_rotate(start, end, tmp, 1);
			pa(end, start);
			break ;
		}
		else if (((tmp->abv_med) == 1) && ((tmp->target->abv_med) == 1)
			&& tmp->cheapest == 1)
		{
			best_r_rotate(start, end, tmp, 1);
			pa(end, start);
			break ;
		}
		else if (((tmp->abv_med) != (tmp->target->abv_med))
			&& tmp->cheapest == 1)
		{
			placement_b(start, end, tmp);
			pa(end, start);
			break ;
		}
		tmp = tmp->next;
	}
}
