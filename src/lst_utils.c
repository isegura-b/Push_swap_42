/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:28:53 by isegura-          #+#    #+#             */
/*   Updated: 2024/12/19 19:34:58 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*find_biggest(t_stack **lst)
{
	t_stack	*biggest;
	int		max;
	t_stack	*tmp_lst;

	max = INT_MIN;
	tmp_lst = *lst;
	biggest = *lst;
	while (tmp_lst)
	{
		if (tmp_lst->num > max)
		{
			max = tmp_lst->num;
			biggest = tmp_lst;
		}
		tmp_lst = tmp_lst->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack **lst)
{
	t_stack	*smallest;
	int		min;
	t_stack	*tmp_lst;

	min = INT_MAX;
	tmp_lst = *lst;
	smallest = *lst;
	while (tmp_lst)
	{
		if (tmp_lst->num < min)
		{
			min = tmp_lst->num;
			smallest = tmp_lst;
		}
		tmp_lst = tmp_lst->next;
	}
	return (smallest);
}

void	go_top(t_stack **a, t_stack *min, int total, int count)
{
	while (min != *a)
	{
		if (count <= total / 2)
			ra(a);
		else
			rra(a);
	}
}
