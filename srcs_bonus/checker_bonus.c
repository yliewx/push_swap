/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:47:07 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 18:47:15 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_stack_sorted(t_data *data, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		i;

	if (stack_b->size > 0)
		end(data, "KO\n", 0);
	current = stack_a->top;
	i = 0;
	while (i < data->size)
	{
		if (current->index > current->next->index
			&& current != stack_a->bottom)
			end(data, "KO\n", 0);
		current = current->next;
		i++;
	}
}

void	parse_instructions(t_data *data, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(data->op, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(data->op, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(data->op, "ss\n", 3) == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(data->op, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(data->op, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(data->op, "ra\n", 3) == 0)
		rotate_up(stack_a);
	else if (ft_strncmp(data->op, "rb\n", 3) == 0)
		rotate_up(stack_b);
	else if (ft_strncmp(data->op, "rr\n", 3) == 0)
		rotate_both_up(stack_a, stack_b);
	else if (ft_strncmp(data->op, "rra\n", 4) == 0)
		rotate_down(stack_a);
	else if (ft_strncmp(data->op, "rrb\n", 4) == 0)
		rotate_down(stack_b);
	else if (ft_strncmp(data->op, "rrr\n", 4) == 0)
		rotate_both_down(stack_a, stack_b);
	else
		end(data, "Error\n", 1);
}

void	read_instructions(t_data *data)
{
	while (1)
	{
		data->op = get_next_line(STDIN_FILENO);
		if (!data->op)
			return ;
		parse_instructions(data, &data->stack_a, &data->stack_b);
		free(data->op);
	}
}
