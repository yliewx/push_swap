/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:06 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 16:45:03 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_lowest_cost(t_stack *stack, t_seq *max_seq)
{
	t_node	*current;
	t_node	*lowest;
	int		i;

	if (stack->size <= 1)
		return (stack->top);
	current = stack->top;
	lowest = NULL;
	i = 0;
	while (i < stack->size)
	{
		if (max_seq && in_seq(max_seq, max_seq->array, current->index))
			current = current->next;
		else
		{
			if (!lowest)
				lowest = current;
			else if (current->move_cost < lowest->move_cost)
				lowest = current;
			current = current->next;
		}
		i++;
	}
	return (lowest);
}

int	find_spot_in_stack(t_stack *dest, t_node **in, t_node *spot)
{
	t_node	*current;
	t_node	*max;
	int		min_diff;
	int		i;

	current = dest->top;
	max = current;
	min_diff = INT_MAX;
	i = 0;
	while (i < dest->size)
	{
		if (current->index > (*in)->index
			&& current->index - (*in)->index < min_diff)
		{
			min_diff = current->index - (*in)->index;
			spot = current;
		}
		if (current->index > max->index)
			max = current;
		current = current->next;
		i++;
	}
	if (!spot)
		return (check_current_pos(dest->top, max->next));
	return (check_current_pos(dest->top, spot));
}

void	update_dest_cost(t_stack *dest, t_node **in)
{
	t_node	*current;
	int		count;

	count = 0;
	current = dest->top;
	count = find_spot_in_stack(dest, in, NULL);
	if (dest->name == 'a' && count == 1 && (*in)->index > dest->top->index
		&& (*in)->index < dest->top->next->index
		&& (*in)->index < dest->bottom->index)
		set_cost(dest, in, to_swap, 1);
	else if (count <= dest->size / 2)
		set_cost(dest, in, up, count);
	else
		set_cost(dest, in, down, dest->size - count);
}

void	update_src_cost(t_stack *src, t_stack *dest)
{
	t_node	*current;
	int		i;
	int		count;

	current = src->top;
	i = 0;
	while (i < src->size)
	{
		reset_cost(&current);
		count = check_current_pos(src->top, current);
		if (count <= src->size / 2)
			set_cost(src, &current, up, count);
		else
			set_cost(src, &current, down, src->size - count);
		if (dest->name == 'a')
			update_dest_cost(dest, &current);
		current = current->next;
		i++;
	}
}

void	set_cost(t_stack *stack, t_node **node, int dir, int count)
{
	if (stack->name == 'a')
	{
		if (dir == up)
			(*node)->ra = count;
		else if (dir == down)
			(*node)->rra = count;
		else if (dir == to_swap)
			(*node)->sa = count;
	}
	else if (stack->name == 'b')
	{
		if (dir == up)
			(*node)->rb = count;
		else if (dir == down)
			(*node)->rrb = count;
		else if (dir == to_swap)
			(*node)->sb = count;
	}
	(*node)->move_cost = (*node)->sa + (*node)->sb + (*node)->ra
		+ (*node)->rb + (*node)->rra + (*node)->rrb + 1;
}
