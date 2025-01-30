/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:17:49 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:07:28 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(t_stack **a, int num)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		write(1, "Error\n", 6);
		free_stack(a);
		exit(1);
	}
	new->num = num;
	new->next = NULL;
	new->direccion = new;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		tmp = ft_lstlast(*a);
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
}

void	ft_fill_stack(t_stack **a, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (av[i])
	{
		num = (int)ft_atol(av[i]);
		new_node(a, num);
		i++;
	}
	return ;
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmpnext;

	if (a || *a)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			tmpnext = tmp->next;
			free(tmp);
			tmp = tmpnext;
		}
	}
}

void	ft_lim_s(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*s;
	int		min;

	tmp = *stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			s = tmp;
		}
		tmp = tmp->next;
	}
	s->min = 1;
}

void	ft_lim_b(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*b;
	int		max;

	tmp = *stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->num > max)
		{
			max = tmp->num;
			b = tmp;
		}
		tmp = tmp->next;
	}
	b->max = 1;
}
