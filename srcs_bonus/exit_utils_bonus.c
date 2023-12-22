/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:10:10 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 13:12:08 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (stack->size < 1)
		return ;
	current = stack->top;
	while (current && current->next != stack->top)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
}

void	free_args(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}

void	end(t_data *data, char *message, int exit_code)
{
	if (message)
	{
		if (exit_code == 1)
			ft_putstr_fd(message, 2);
		else if (exit_code == 0)
			ft_putstr_fd(message, 1);
	}
	if (data->valid_input)
	{
		free_stack(&data->stack_a);
		free_stack(&data->stack_b);
	}
	if (data->temp_args)
		free_args(&data->temp_args);
	if (data->array_c)
		free(data->array_c);
	if (data->op)
		free(data->op);
	exit(exit_code);
}
