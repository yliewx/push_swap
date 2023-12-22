/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:36:22 by yliew             #+#    #+#             */
/*   Updated: 2023/12/18 17:36:31 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_max_seq(t_seq **max_seq, t_node *end)
{
	(*max_seq)->len = end->seq_len;
	(*max_seq)->end = end;
}

void	copy_seq(int *src, int **dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*dest)[i] = src[i];
		i++;
	}
}

void	finalise_seq(t_data *data, t_seq *max_seq)
{
	int	i;

	max_seq->array = max_seq->lis[max_seq->end->index];
	i = 0;
	while (i < data->size)
	{
		if (i != max_seq->end->index)
			free(max_seq->lis[i]);
		i++;
	}
	free(max_seq->lis);
}
