/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:06:43 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/02 15:51:40 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.  */

void	reverse_rotate(t_stack *stack)
{
	t_list *last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;

	last->next = stack->top;
	stack->top->prior = last;

	stack->bottom = last->prior;
	stack->bottom->next = NULL;

	stack->top = last;
	stack->top->prior = NULL;
}

void	rra(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
