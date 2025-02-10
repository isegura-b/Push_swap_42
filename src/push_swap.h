/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:09:28 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/07 16:54:02 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				min;
	int				max;
	int				abv_med;
	int				cost;
	int				cheapest;

	struct s_stack	*next;
	struct s_stack	*direccion;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

int					is_num(char **av);
long				ft_atol(char *av);
int					is_dup(char **av);
int					int_error(char **av);
int					ft_parsing(char **av);
int					ft_sorted(t_stack **a);
void				ft_small_sort(t_stack **a, int ac);
void				ft_sort_3(t_stack **a);
void				ft_sort_4(t_stack **a, t_stack **b);
void				ft_algorithm_sort(t_stack **a, t_stack **b, int flag);
void				target_a(t_stack **a, t_stack **b);
void				target_b(t_stack **b, t_stack **a);
t_stack				*find_biggest(t_stack **lst);
t_stack				*find_smallest(t_stack **lst);
void				ft_index(t_stack **a, t_stack **b);
void				cost_all_down(t_stack **start, t_stack **end);
void				cost_start_down(t_stack **start);
void				cost_start_up(t_stack **start);
void				cost_all_up(t_stack **start);
void				ft_cost(t_stack **start, t_stack **end);
void				above_median(t_stack **stack);
void				ft_cheapest(t_stack **stack);
t_stack				*new_node(t_stack **a, int num);
void				ft_fill_stack(t_stack **a, char **av);
void				free_stack(t_stack **a);
void				ft_lim_b(t_stack **stack);
void				ft_lim_s(t_stack **stack);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstfirst(t_stack *lst);
void				prints(t_stack *node);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				push(t_stack **end, t_stack **start);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rev_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				best_mv_a(t_stack **start, t_stack **end);
void				best_mv_b(t_stack **start, t_stack **end);
void				placement_a(t_stack **start, t_stack **end,
						t_stack *cheapest);
void				best_r_rotate(t_stack **start, t_stack **end,
						t_stack *cheapest, int flag);
void				best_rotate(t_stack **start, t_stack **end,
						t_stack *cheapest, int flag);
void				placement_b(t_stack **start, t_stack **end,
						t_stack *cheapest);
void				push_smallest(t_stack **a);
void				go_top(t_stack **a, t_stack *min, int total, int count);
void				clean(t_stack **stack);
void				move_a(t_stack **start, t_stack **end, t_stack *tmp);
void				move_b(t_stack **start, t_stack **end, t_stack *tmp);

#endif
