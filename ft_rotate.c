/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:06:18 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/01 21:09:44 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
*/

void	rotate(t_stack *stack)
{
	t_list	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;

	first->prior = stack->bottom;
	stack->bottom->next = first;

	stack->top = first->next;
	stack->top->prior = NULL;

	stack->bottom = first;
	stack->bottom->next = NULL;
}

void	ra(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

