/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:29:43 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 19:03:17 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *stack, int index)
{
	t_node	*current;
	int		dir;

	current = get_node_from_index(stack, index);
	if (check_current_pos(stack->top, current) <= stack->size / 2)
		dir = up;
	else
		dir = down;
	while (stack->top != current)
		rotate(dir, 1, stack, NULL);
}

void	sort_advanced(t_data *data, t_stack *stack_a, t_stack *stack_b)
{
	find_longest_seq(stack_a, &stack_a->top, &data->max_seq);
	finalise_seq(data, &data->max_seq);
	update_src_cost(stack_a, stack_b);
	move_best_nodes(stack_a, stack_b, &data->max_seq, data->max_seq.len);
	update_src_cost(stack_b, stack_a);
	move_best_nodes(stack_b, stack_a, NULL, 0);
	if (stack_a->top->index != 0)
		rotate_to_top(stack_a, 0);
}
