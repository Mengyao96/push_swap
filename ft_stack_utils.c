/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utsils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:49:52 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/02 16:09:20 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

// put all inputs in to the stack by lstadd_back
/// create a new node first
t_list	*ft_lstnew_ps(long input)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->value = input;
	node->prior = NULL;
	node->next = NULL;
	return (node);
}

/// add a new node to the end of the stack
void	ft_lstadd_back_ps(t_stack *stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		return ;
	}
	new_node->prior = stack->bottom;
	stack->bottom->next = new_node;
	stack->bottom = new_node;
}

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next_node;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = current->next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
