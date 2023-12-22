/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:00 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 15:22:59 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(t_node *node)
{
	ft_printf(LIGHT"total moves: %i\t| ", node->move_cost);
	if (node->sa != 0)
		ft_printf("sa: %i, ", node->sa);
	if (node->sb != 0)
		ft_printf("sb: %i, ", node->sb);
	if (node->ra != 0)
		ft_printf("ra: %i, ", node->ra);
	if (node->rb != 0)
		ft_printf("rb: %i, ", node->rb);
	if (node->rra != 0)
		ft_printf("rra: %i, ", node->rra);
	if (node->rrb != 0)
		ft_printf("rrb: %i", node->rrb);
	ft_printf("\nsubseq_len: %i\n"RESET, node->seq_len);
}

void	print_stack(t_stack stack)
{
	t_node	*node;
	int		i;

	ft_printf(GREEN"\nCurrent stack %c:\t(Size: %i)\n"RESET,
		stack.name, stack.size);
	node = stack.top;
	i = 0;
	while (i < stack.size)
	{
		ft_printf("[%i] nbr: %i", node->index, node->nbr);
		if (node->prev)
			ft_printf(BROWN"\t| prev: %i"RESET, node->prev->nbr);
		else
			ft_printf("\t\t");
		if (node->next)
			ft_printf(BROWN"\t| next: %i\n"RESET, node->next->nbr);
		else
			ft_printf("\n\n");
		print_moves(node);
		node = node->next;
		i++;
	}
}

void	print_stacks(t_stack a, t_stack b)
{
	print_stack(a);
	print_stack(b);
}
