/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:08:29 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/31 18:17:27 by mezhang          ###   ########.fr       */
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

void	sa(t_stack *stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	// if (!first || !second)
	// 	return ;
	first->next = second->next;
	if (first->next)
		first->next->prior = first;
	second->next = first;
	first->prior = second;
	second->prior = NULL;
	stack_a->top = second;
}

void	sb(t_stack *stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	// if (!first || !second)
	// 	return ;
	first->next = second->next;
	if (first->next)
		first->next->prior = first;
	second->next = first;
	first->prior = second;
	second->prior = NULL;
	stack_b->top = second;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
}
