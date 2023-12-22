/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:05 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 14:12:35 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*[ra/rb] move first element to bottom*/
void	rotate_up(t_stack *stack, bool rr)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (stack->size <= 1)
		return ;
	new_bottom = stack->top;
	new_top = stack->top->next;
	stack->bottom = new_bottom;
	stack->top = new_top;
	if (!rr)
	{
		if (stack->name == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

/*[rra/rrb] move last element to top*/
void	rotate_down(t_stack *stack, bool rrr)
{
	t_node	*new_bottom;
	t_node	*new_top;

	if (stack->size <= 1)
		return ;
	new_top = stack->bottom;
	new_bottom = stack->bottom->prev;
	stack->bottom = new_bottom;
	stack->top = new_top;
	if (!rrr)
	{
		if (stack->name == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

/*[rr] rotate both*/
void	rotate_both_up(t_stack *stack_a, t_stack *stack_b)
{
	rotate_up(stack_a, true);
	rotate_up(stack_b, true);
	ft_printf("rr\n");
}

/*[rrr] reverse rotate both*/
void	rotate_both_down(t_stack *stack_a, t_stack *stack_b)
{
	rotate_down(stack_a, true);
	rotate_down(stack_b, true);
	ft_printf("rrr\n");
}

void	rotate(int dir, int times, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b && dir == up)
	{
		while (times-- > 0)
			rotate_both_up(stack_a, stack_b);
	}
	else if (stack_a && stack_b && dir == down)
	{
		while (times-- > 0)
			rotate_both_down(stack_a, stack_b);
	}
	else if (dir == up)
	{
		while (times-- > 0)
			rotate_up(stack_a, false);
	}
	else if (dir == down)
	{
		while (times-- > 0)
			rotate_down(stack_a, false);
	}
}
