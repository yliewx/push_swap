/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:05 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 14:12:35 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*[ra/rb] move first element to bottom*/
void	rotate_up(t_stack *stack)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (stack->size <= 1)
		return ;
	new_bottom = stack->top;
	new_top = stack->top->next;
	stack->bottom = new_bottom;
	stack->top = new_top;
}

/*[rra/rrb] move last element to top*/
void	rotate_down(t_stack *stack)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (stack->size <= 1)
		return ;
	new_top = stack->bottom;
	new_bottom = stack->bottom->prev;
	stack->bottom = new_bottom;
	stack->top = new_top;
}

/*[rr] rotate both*/
void	rotate_both_up(t_stack *stack_a, t_stack *stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
}

/*[rrr] reverse rotate both*/
void	rotate_both_down(t_stack *stack_a, t_stack *stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
}
