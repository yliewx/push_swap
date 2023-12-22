/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:45:57 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 17:55:17 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition_array(t_stack *stack, int *arr, int start, int end)
{
	int		pivot;
	t_node	*to_swap_1;
	t_node	*to_swap_2;

	pivot = arr[(start + end) / 2];
	{
		while (arr[start] < pivot)
			start++;
		while (arr[end] > pivot)
			end--;
		if (start <= end)
		{
			ft_swap(&arr[start], &arr[end]);
			to_swap_1 = get_node_from_index(stack, start);
			to_swap_2 = get_node_from_index(stack, end);
			ft_swap(&to_swap_1->index, &to_swap_2->index);
			start++;
			end--;
		}
	}
	return (start);
}

void	sort_index(t_stack *stack, int *arr, int start, int end)
{
	int	pivot;

	pivot = partition_array(stack, arr, start, end);
	if (start < pivot - 1)
		sort_index(stack, arr, start, pivot - 1);
	if (end > pivot)
		sort_index(stack, arr, pivot, end);
}
