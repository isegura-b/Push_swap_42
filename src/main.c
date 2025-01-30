/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:49:12 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/14 16:08:12 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || ft_parsing(av))
		return (0);
	ft_fill_stack(&a, av);
	if (ft_sorted(&a))
	{
		if (ac <= 4)
			ft_small_sort(&a, ac);
		if (ac == 5)
		{
			ft_algorithm_sort(&a, &b, 0);
		}
		if (ac > 5)
		{
			ft_algorithm_sort(&a, &b, 1);
		}
	}
	free_stack(&a);
	return (0);
}
