/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:47:07 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 18:47:15 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_double(t_stack *stack_a, t_stack *stack_b, t_node *current)
{
	while (current->ra > 0 && current->rb > 0)
	{
		rotate_both_up(stack_a, stack_b);
		current->ra--;
		current->rb--;
	}
	while (current->rra > 0 && current->rrb > 0)
	{
		rotate_both_down(stack_a, stack_b);
		current->rra--;
		current->rrb--;
	}
}

void	move_single(t_stack *stack_a, t_stack *stack_b, t_node *current)
{
	while (current->ra > 0)
	{
		rotate_up(stack_a, false);
		current->ra--;
	}
	while (current->rra > 0)
	{
		rotate_down(stack_a, false);
		current->rra--;
	}
	while (current->rb > 0)
	{
		rotate_up(stack_b, false);
		current->rb--;
	}
	while (current->rrb > 0)
	{
		rotate_down(stack_b, false);
		current->rrb--;
	}
}

void	move_best_nodes(t_stack *src, t_stack *dest, t_seq *max_seq, int end)
{
	t_node	*current;

	current = find_lowest_cost(src, max_seq);
	if (!current || src->size == end)
		return ;
	if (src->name == 'a')
	{
		move_single(src, dest, current);
		push(src, dest);
	}
	else
	{
		move_double(dest, src, current);
		move_single(dest, src, current);
		push(src, dest);
		if (current->sa > 0)
		{
			swap(dest, false);
			current->sa--;
		}
	}
	update_src_cost(src, dest);
	move_best_nodes(src, dest, max_seq, end);
}

int	check_current_pos(t_node *start, t_node *end)
{
	int	i;

	i = 0;
	while (start != end)
	{
		start = start->next;
		i++;
	}
	return (i);
}

bool	in_seq(t_seq *max_seq, int *lis, int current)
{
	int	i;

	i = 0;
	while (i < max_seq->len)
	{
		if (lis[i] == current)
			return (true);
		i++;
	}
	return (false);
}
