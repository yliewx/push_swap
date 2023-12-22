/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:30:43 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 15:06:16 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reset_cost(t_node **node)
{
	(*node)->move_cost = 0;
	(*node)->sa = 0;
	(*node)->sb = 0;
	(*node)->ra = 0;
	(*node)->rb = 0;
	(*node)->rra = 0;
	(*node)->rrb = 0;
}

t_node	*new_node(int nbr, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	new->seq_len = 1;
	reset_cost(&new);
	return (new);
}

void	add_to_bottom(t_stack *stack, t_node *new)
{
	t_node	*old_bottom;

	old_bottom = stack->bottom;
	stack->bottom = new;
	set_link(&old_bottom, to_next, NULL, new);
	set_link(&new, to_prev, old_bottom, NULL);
}

void	set_link(t_node **node, int type, t_node *new_prev, t_node *new_next)
{
	if (type == to_prev || type == to_both)
		(*node)->prev = new_prev;
	if (type == to_next || type == to_both)
		(*node)->next = new_next;
}

t_node	*get_node_from_index(t_stack *stack, int index_to_find)
{
	t_node	*current;

	current = stack->top;
	while (current->index != index_to_find)
		current = current->next;
	return (current);
}
