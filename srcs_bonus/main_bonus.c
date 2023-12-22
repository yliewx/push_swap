/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:00 by yliew             #+#    #+#             */
/*   Updated: 2023/12/11 15:22:59 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_array(t_data *data, int argc, char **argv, bool single_str)
{
	long	nbr;
	int		i;
	int		j;

	i = 0;
	if (single_str)
	{
		j = 0;
		while (argv[data->size])
			data->size++;
	}
	else
	{
		j = 1;
		data->size = argc - 1;
	}
	data->array_c = malloc(data->size * sizeof(int));
	while (i < data->size)
	{
		nbr = ft_atoi_long(argv[j++]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			end(data, "Error\n", 1);
		data->array_c[i++] = nbr;
	}
}

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int *arr, int size)
{
	int	i;

	stack_b->name = 'b';
	stack_b->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_a->name = 'a';
	stack_a->size = size;
	stack_a->top = new_node(arr[0], 0);
	stack_a->bottom = stack_a->top;
	i = 1;
	while (i < size)
	{
		add_to_bottom(stack_a, new_node(arr[i], i));
		i++;
	}
	set_link(&stack_a->bottom, to_next, NULL, stack_a->top);
	set_link(&stack_a->top, to_prev, stack_a->bottom, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	check_params(&data, argc, argv);
	init_stacks(&data.stack_a, &data.stack_b, data.array_c, data.size);
	sort_index(&data.stack_a, data.array_c, 0, data.size - 1);
	read_instructions(&data);
	check_stack_sorted(&data, &data.stack_a, &data.stack_b);
	end(&data, "OK\n", 0);
	return (0);
}
