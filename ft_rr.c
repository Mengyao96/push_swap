/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:06:43 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/31 18:45:35 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.  */

void	rra(t_stack *stack_a)
{
	t_list *last;

	if (!stack_a || stack_a->size < 2)
		return ;
	last = stack_a->bottom;

	last->next = stack_a->top;
	stack_a->top->prior = last;

	stack_a->bottom = last->prior;
	stack_a->bottom->next = NULL;

	stack_a->top = last;
	stack_a->top->prior = NULL;
}

void	rrb(t_stack *stack_b)
{
	t_list *last;

	if (!stack_b || stack_b->size < 2)
		return ;
	last = stack_b->bottom;

	last->next = stack_b->top;
	stack_b->top->prior = last;

	stack_b->bottom = last->prior;
	stack_b->bottom->next = NULL;

	stack_b->top = last;
	stack_b->top->prior = NULL;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	rra(stack_a);
	rrb(stack_b);
}
