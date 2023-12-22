/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:09:50 by yliew             #+#    #+#             */
/*   Updated: 2023/12/18 17:09:51 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/*text colour*/

# define BROWN "\033[1;33m"
# define LIGHT "\033[0;33m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

enum e_type
{
	to_prev,
	to_next,
	to_both,
	up,
	down,
	to_swap,
};

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
	int				seq_len;
	int				move_cost;
	int				sa;
	int				sb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}	t_node;

typedef struct s_stack
{
	char	name;
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*array_c;
	int		size;
	bool	valid_input;
	char	*op;
	char	**temp_args;
}	t_data;

/*init.c*/
void	init_array(t_data *data, int argc, char **argv, bool single_str);

/*checker_bonus.c*/
void	read_instructions(t_data *data);
void	check_stack_sorted(t_data *data, t_stack *stack_a, t_stack *stack_b);

/*verify_params.c*/
void	check_params(t_data *data, int argc, char **argv);
void	check_numeric(t_data *data, int argc, char **argv);
void	check_numeric_single_str(t_data *data, char *arg);
void	check_duplicate(t_data *data, int *arr, int size);

/*stack_utils.c*/
t_node	*new_node(int nbr, int index);
void	reset_cost(t_node **node);
void	add_to_bottom(t_stack *stack, t_node *new);
void	set_link(t_node **node, int type, t_node *new_prev, t_node *new_next);
t_node	*get_node_from_index(t_stack *stack, int index_to_find);

/*op_swap.c*/
void	swap(t_stack *stack);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

/*op_push.c*/
void	push(t_stack *src, t_stack *dest);

/*op_rotate.c*/
void	rotate_up(t_stack *stack);
void	rotate_both_up(t_stack *stack_a, t_stack *stack_b);
void	rotate_down(t_stack *stack);
void	rotate_both_down(t_stack *stack_a, t_stack *stack_b);

/*sort_index.c*/
void	sort_index(t_stack *stack, int *arr, int start, int end);

/*exit_utils.c*/
void	end(t_data *data, char *message, int exit_code);

/*print_stacks.c (checking)*/
void	print_stack(t_stack stack);
void	print_stacks(t_stack a, t_stack b);
void	print_moves(t_node *node);

#endif
