/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:08:29 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/01 21:08:33 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one element or none.
ss : sa and sb at the same time.
 */

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	// if (!first || !second)
	// 	return ;
	first->next = second->next;
	if (first->next)
		first->next->prior = first;
	second->next = first;
	first->prior = second;
	second->prior = NULL;
	stack->top = second;
}

void	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
