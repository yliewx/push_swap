/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:05 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 14:26:19 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*[sa/sb] swap the first 2 elements at the top of the stack
and update the prev/next pointers accordingly
if elements <= 1, do nothing*/
void	swap(t_stack *stack)
{
	t_node	*new_1st;
	t_node	*new_2nd;

	if (stack->size <= 1)
		return ;
	new_1st = stack->top->next;
	new_2nd = stack->top;
	stack->top = new_1st;
	if (stack->size == 2)
		stack->bottom = new_2nd;
	else
	{
		set_link(&stack->bottom, to_next, NULL, new_1st);
		set_link(&new_2nd, to_both, new_1st, new_1st->next);
		set_link(&new_1st, to_both, stack->bottom, new_2nd);
		set_link(&new_2nd->next, to_prev, new_2nd, NULL);
	}
}

/*[ss]*/
void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
