/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:29:43 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 16:45:19 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
(A < B && A < C && B > C) //1 3 2
	1. rra (rotate a down)	//2 1 3
	2. sa (swap a)		//1 2 3 ✅
(A < B && A > C && B > C) //2 3 1
	1. rra (rotate a down)	//1 2 3 ✅
(A > B && A < C && B < C) //2 1 3
	1. sa (swap a)		//1 2 3 ✅
(A > B && A > C && B < C) //3 1 2
	1. ra (rotate a up)	//1 2 3 ✅
(A > B && A > C && B > C) //3 2 1
	1. ra (rotate a up)	//2 1 3
	2. sa (swap a)		//1 2 3 ✅
*/
void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->index;
	b = stack->top->next->index;
	c = stack->top->next->next->index;
	if (a < b && b < c)
		return ;
	if (a < b && a < c && b > c)
	{
		rotate_down(stack, false);
		swap(stack, false);
	}
	else if (a < b && a > c && b > c)
		rotate_down(stack, false);
	else if (a > b && a < c && b < c)
		swap(stack, false);
	else if (a > b && a > c && b < c)
		rotate_up(stack, false);
	else if (a > b && a > c && b > c)
	{
		rotate_up(stack, false);
		swap(stack, false);
	}
}

void	trim_stack(int start, int max, t_stack *src, t_stack *dest)
{
	t_node	*current;
	int		dir;

	if (start == max)
		return ;
	current = get_node_from_index(src, start);
	if (check_current_pos(src->top, current) <= src->size / 2)
		dir = up;
	else
		dir = down;
	while (src->top != current)
	{
		if (current->prev == src->top)
		{
			if (src->top->index > src->bottom->index)
				rotate_up(src, false);
			else
				swap(src, false);
			break ;
		}
		rotate(dir, 1, src, NULL);
	}
	push(src, dest);
	trim_stack(start + 1, max, src, dest);
}

/*find the longest consecutive sequence
if max_len == stack size - 1, ra or rra

to optimise:
3 4 0 1 2 (6 moves, can be done in 2)
0 2 3 4 1 (5 moves, can be done in 2)
1 0 2 3 4 (5 moves, can be done in 1)*/
void	sort_seq_3_other(t_stack *stack, t_seq *max_seq)
{
	if (stack->top->index == max_seq->start->index)
	{
		rotate(down, 2, stack, NULL);
		if (stack->top->index != 0 || stack->top->next->index != 1)
			swap(stack, false);
		if (max_seq->start->index == 0 || max_seq->start->index == 1)
			rotate_up(stack, false);
		if (max_seq->start->index == 0)
			rotate_up(stack, false);
	}
	else
	{
		rotate_down(stack, false);
		swap(stack, false);
		if (max_seq->start->index == 0 || max_seq->start->index == 1)
			rotate_up(stack, false);
		if (max_seq->start->index == 0)
			rotate_up(stack, false);
	}
}

void	sort_seq_3(t_stack *stack, t_seq *max_seq)
{
	t_node	*before_seq;
	t_node	*after_seq;

	before_seq = max_seq->start->prev;
	after_seq = max_seq->end->next;
	if (max_seq->end->index == 4 && stack->bottom->index == 4)
		swap(stack, false);
	else if (max_seq->end->index == 3 && stack->bottom->index == 3)
	{
		swap(stack, false);
		rotate_up(stack, false);
	}
	else if (max_seq->end->index == 2 && stack->bottom->index == 2)
	{
		if (before_seq->index < after_seq->index)
			swap(stack, false);
		rotate(up, 2, stack, NULL);
	}
	else
		sort_seq_3_other(stack, max_seq);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b, t_seq *max_seq)
{
	find_longest_consecutive_seq(stack_a, &max_seq);
	if (max_seq->len == stack_a->size - 1)
	{
		if (stack_a->top->index == max_seq->start->index)
			rotate_down(stack_a, false);
		else
			rotate_up(stack_a, false);
		return ;
	}
	else if (max_seq->len == 3)
	{
		sort_seq_3(stack_a, max_seq);
		return ;
	}
	trim_stack(0, stack_a->size - 3, stack_a, stack_b);
	sort_3(stack_a);
	while (stack_b->size > 0)
		push(stack_b, stack_a);
}
