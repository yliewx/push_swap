/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_params_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:39:07 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 15:09:30 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_params(t_data *data, int argc, char **argv)
{
	data->valid_input = false;
	data->array_c = NULL;
	data->temp_args = NULL;
	data->op = NULL;
	data->size = 0;
	if (argc == 2)
	{
		check_numeric_single_str(data, argv[1]);
		data->temp_args = ft_split(argv[1], ' ');
		init_array(data, argc, data->temp_args, true);
	}
	else
	{
		check_numeric(data, argc, argv);
		init_array(data, argc, argv, false);
	}
	check_duplicate(data, data->array_c, data->size);
	data->valid_input = true;
}

void	check_numeric(t_data *data, int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (i == 0 && argv[j][i] == '-')
				i++;
			if (!ft_isdigit(argv[j][i]))
				end(data, "Error\n", 1);
			i++;
		}
		j++;
	}
}

void	check_numeric_single_str(t_data *data, char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((i == 0 && arg[i] == '-')
			|| (arg[i] == '-' && ft_isdigit(arg[i + 1])))
			i++;
		if (!ft_isdigit(arg[i]) && arg[i] != ' ')
			end(data, "Error\n", 1);
		i++;
	}
}

void	check_duplicate(t_data *data, int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				end(data, "Error\n", 1);
			j++;
		}
		i++;
	}
}
