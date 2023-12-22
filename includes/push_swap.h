/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:25 by yliew             #+#    #+#             */
/*   Updated: 2023/12/18 17:15:22 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
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

typedef struct s_seq
{
	int		**lis;
	int		*array;
	int		len;
	t_node	*start;
	t_node	*end;
}	t_seq;

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
	t_seq	max_seq;
	char	**temp_args;
}	t_data;

/*init.c*/
void	init_array(t_data *data, int argc, char **argv, bool single_str);

/*verify_params.c*/
void	check_params(t_data *data, int argc, char **argv);
void	check_numeric(t_data *data, int argc, char **argv);
void	check_numeric_single_str(t_data *data, char *arg);
void	check_duplicate(t_data *data, int *arr, int size);
bool	is_sorted(int *arr, int size);

/*stack_utils.c*/
t_node	*new_node(int nbr, int index);
void	reset_cost(t_node **node);
void	add_to_bottom(t_stack *stack, t_node *new);
void	set_link(t_node **node, int type, t_node *new_prev, t_node *new_next);
t_node	*get_node_from_index(t_stack *stack, int index_to_find);

/*op_swap.c*/
void	swap(t_stack *stack, bool ss);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

/*op_push.c*/
void	push(t_stack *src, t_stack *dest);

/*op_rotate.c*/
void	rotate(int dir, int times, t_stack *stack_a, t_stack *stack_b);
void	rotate_up(t_stack *stack, bool rr);
void	rotate_both_up(t_stack *stack_a, t_stack *stack_b);
void	rotate_down(t_stack *stack, bool rrr);
void	rotate_both_down(t_stack *stack_a, t_stack *stack_b);

/*moves.c*/
void	move_best_nodes(t_stack *src, t_stack *dest, t_seq *max_seq, int end);
int		check_current_pos(t_node *start, t_node *end);
bool	in_seq(t_seq *max_seq, int *lis, int current);

/*sort_index.c*/
void	sort_index(t_stack *stack, int *arr, int start, int end);

/*sort_simple.c*/
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b, t_seq *max_seq);

/*sort_advanced.c*/
void	sort_advanced(t_data *data, t_stack *stack_a, t_stack *stack_b);

/*move_cost.c*/
t_node	*find_lowest_cost(t_stack *stack, t_seq *max_seq);
void	update_dest_cost(t_stack *dest, t_node **in);
void	update_src_cost(t_stack *src, t_stack *dest);
void	set_cost(t_stack *stack, t_node **node, int dir, int count);

/*sequence.c*/
void	find_longest_seq(t_stack *stack, t_node **end, t_seq *max_seq);
void	find_longest_consecutive_seq(t_stack *stack, t_seq **max_seq);

/*sequence_utils.c*/
void	update_max_seq(t_seq **max_seq, t_node *end);
void	copy_seq(int *src, int **dest, int size);
void	finalise_seq(t_data *data, t_seq *max_seq);

/*exit_utils.c*/
void	end(t_data *data, char *message, int exit_code);

/*print_stacks.c (checking)*/
void	print_stack(t_stack stack);
void	print_stacks(t_stack a, t_stack b);
void	print_moves(t_node *node);

#endif
