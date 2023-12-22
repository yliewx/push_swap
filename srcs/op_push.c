/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:38:05 by yliew             #+#    #+#             */
/*   Updated: 2023/12/05 15:51:26 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_src(t_stack **src)
{
	if ((*src)->top->next)
	{
		(*src)->top = (*src)->top->next;
		if ((*src)->size == 1)
			(*src)->bottom = (*src)->top;
		set_link(&(*src)->top, to_prev, (*src)->bottom, NULL);
		set_link(&(*src)->bottom, to_next, NULL, (*src)->top);
	}
	else
	{
		(*src)->top = NULL;
		(*src)->bottom = NULL;
	}
}

void	update_dest(t_stack **dest, t_node **new_1st, t_node **new_2nd)
{
	if ((*dest)->size == 2)
		(*dest)->bottom = *new_2nd;
	else if ((*dest)->size == 1)
	{
		(*dest)->bottom = *new_1st;
		*new_2nd = *new_1st;
	}
	set_link(new_1st, to_both, (*dest)->bottom, *new_2nd);
	set_link(&(*dest)->bottom, to_next, NULL, (*dest)->top);
	if (*new_2nd)
		set_link(new_2nd, to_prev, (*dest)->top, NULL);
}

/*[pa] push a: take from b, push to a
[pb] push b: take from a, push to b*/
void	push(t_stack *src, t_stack *dest)
{
	t_node	*dest_new_1st;
	t_node	*dest_new_2nd;

	if (src->size == 0)
		return ;
	src->size -= 1;
	dest->size += 1;
	dest_new_1st = src->top;
	dest_new_2nd = dest->top;
	dest->top = dest_new_1st;
	update_src(&src);
	update_dest(&dest, &dest_new_1st, &dest_new_2nd);
	if (dest->name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
