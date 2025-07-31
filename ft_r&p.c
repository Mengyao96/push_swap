/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_n_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:06:18 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/31 19:14:46 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/

void	ra(t_stack *stack_a)
{
	t_list	*first;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;

	first->prior = stack_a->bottom;
	stack_a->bottom->next = first;

	stack_a->top = first->next;
	stack_a->top->prior = NULL;

	stack_a->bottom = first;
	stack_a->bottom->next = NULL;
}

void	rb(t_stack *stack_b)
{
	t_list	*first;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;

	//first <-> bottom
	first->prior = stack_b->bottom;
	stack_b->bottom->next = first;

	//shitf the top: node itselt + node prior
	stack_b->top = first->next;
	stack_b->top->prior = NULL;

	// shift the bottom: node itselt + node next
	stack_b->bottom = first;
	stack_b->bottom->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	ra(stack_a);
	rb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;

	if (!stack_b || stack_b->size < 1)
		return ;
	first = stack_b->top;

	if (!stack_a || stack_a->size < 1)
		return (ft_lstadd_back_ps(stack_a, first));

	stack_b->top = first->next;
	if (!stack_b->top)
		stack_b->bottom = NULL;
	else
		stack_b->top->prior = NULL;

	first->next = stack_a->top;
	stack_a->top->prior = first;

	stack_a->top = first;
	stack_a->top->prior = NULL;

	stack_a->size++;
	stack_b->size--;

}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;

	if (!stack_a || stack_a->size < 1)
		return ;
	first = stack_a->top;

	if (!stack_b || stack_b->size < 1)
		return (ft_lstadd_back_ps(stack_b, first));

	stack_a->top = first->next;
	if (!stack_a->top)
		stack_a->bottom = NULL;
	else
		stack_a->top->prior = NULL;

	first->next = stack_b->top;
	stack_b->top->prior = first;

	stack_b->top = first;
	stack_b->top->prior = NULL;

	stack_b->size++;
	stack_a->size--;

}
