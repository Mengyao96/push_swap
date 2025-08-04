/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:06:18 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/04 23:04:27 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;

	if (!stack_b || stack_b->size < 1)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	if (!stack_b->top)
		stack_b->bottom = NULL;
	else
		stack_b->top->prior = NULL;
	stack_b->size--;
	first->prior = NULL; // not redundant, but for clarity
	if (!stack_a || stack_a->size < 1)
	{
		first->next = NULL;
		ft_lstadd_back_ps(stack_a, first);
	}
	else
	{
		first->next = stack_a->top;
		stack_a->top->prior = first;
		stack_a->top = first;
		stack_a->size++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;

	if (!stack_a || stack_a->size < 1)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	if (!stack_a->top)
		stack_a->bottom = NULL;
	else
		stack_a->top->prior = NULL;
	stack_a->size--;
	first->prior = NULL; // not redundant, but for clarity
	if (!stack_b->top)
	{
		first->next = NULL;
		ft_lstadd_back_ps(stack_b, first);
	}
	else
	{
		first->next = stack_b->top;
		stack_b->top->prior = first;
		stack_b->top = first;
		stack_b->size++;
	}
	write(1, "pb\n", 3);
}

