/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:05 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 15:51:26 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
- LIS = longest increasing subsequence; use for larger sets of numbers
- lis[i] points to an array of numbers in the LIS that ends with i
- if end_seq->len is greater than the current max_seq->len,
update max_seq->len and max_seq->end
*/
void	find_longest_seq(t_stack *stack, t_node **end, t_seq *max_seq)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = (*end)->index;
	max_seq->lis[i] = malloc(sizeof(int));
	while (current != *end)
	{
		if (i > current->index && (!max_seq->lis[i]
				|| (*end)->seq_len < current->seq_len + 1))
		{
			free(max_seq->lis[i]);
			(*end)->seq_len = current->seq_len + 1;
			max_seq->lis[i] = malloc((*end)->seq_len * sizeof(int));
			copy_seq(max_seq->lis[current->index],
				&max_seq->lis[i], (*end)->seq_len - 1);
		}
		current = current->next;
	}
	max_seq->lis[i][(*end)->seq_len - 1] = i;
	if ((*end)->seq_len > max_seq->len)
		update_max_seq(&max_seq, *end);
	if ((*end)->next != stack->top)
		find_longest_seq(stack, &(*end)->next, max_seq);
}

/*consecutive seq for sorting ~5 numbers*/
void	count_sequence_len(t_node *start, t_node *top, t_seq **max_seq)
{
	t_node	*current;
	int		len;

	current = start;
	len = 1;
	while (current->next != top && current->next->index == current->index + 1)
	{
		len++;
		current = current->next;
	}
	if (len > (*max_seq)->len)
	{
		(*max_seq)->len = len;
		(*max_seq)->start = start;
		(*max_seq)->end = current;
	}
}

void	find_longest_consecutive_seq(t_stack *stack, t_seq **max_seq)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (i < stack->size)
	{
		if (current->next->index == current->index + 1)
			count_sequence_len(current, stack->top, max_seq);
		current = current->next;
		i++;
	}
	i = 0;
	current = (*max_seq)->start;
	(*max_seq)->array = malloc((*max_seq)->len * sizeof(int));
	while (i < (*max_seq)->len)
	{
		(*max_seq)->array[i] = current->index;
		current = current->next;
		i++;
	}
}
