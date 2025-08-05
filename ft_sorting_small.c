/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:02:40 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/05 16:39:26 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sorting_three(t_stack *stack_a)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (!stack_a || stack_a->size > 3)
		return ;
	a = stack_a->top;
	b = a->next;
	c = b->next;
	if (a->value > b->value)
		sa(stack_a);
	if (!c)
		return ;
	if (a->value > c->value)
	{
		rra(stack_a);
		if (c->value > b->value)
			sa(stack_a);
	}
	else if (b->value > c->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

/* static t_list	*get_min_node(t_stack *stack_a, int *index)
{
	int		min_value;
	t_list	*current;
	t_list	*min_node;
	int		i;

	if (!stack_a || stack_a->size == 0)
		return (NULL);
	current = stack_a->top;
	min_value = current->value;
	i = 0;
	while (current)
	{
		if (current->value <= min_value)
		{
			min_value = current->value;
			min_node = current;
			*index = i;
		}
		current = current->next;
		i++;
	}
	return (min_node);
} */

static int	min_index(t_stack *stack_a)
{
	int		min_value;
	t_list	*current;
	int		i;
	int		index;

	if (!stack_a || stack_a->size == 0)
		return (0);
	current = stack_a->top;
	min_value = current->value;
	i = 0;
	index = -1;
	while (current)
	{
		if (current->value <= min_value)
		{
			min_value = current->value;
			index = i;
		}
		current = current->next;
		i++;
	}
	return (index);
}

void	ft_sorting_small(t_stack *stack_a, t_stack *stack_b)
{
	int		index;

	if (!stack_a /* || stack_a->size > 5 */)
		return ;
	if (stack_a->size <= 3)
		ft_sorting_three(stack_a);
	else
	{
		index = min_index(stack_a);
		if (index <= stack_a->size / 2)
		{
			while (index-- > 0)
				ra(stack_a);
		}
		else
		{
			while (index++ < stack_a->size)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		ft_sorting_small(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	ft_get_stack_index(t_stack *stack_a)
{
	t_list	*current;
	t_list	*min_node;
	int		index;
	int		i;

	index = -1;
	i = 0;
	while (i < stack_a->size)
	{
		current = stack_a->top;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && (!min_node || current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
		min_node->index = i++;
	}
}

int	ft_is_sorted(t_stack *stack_a)
{
	t_list	*current;

	if (!stack_a || stack_a->size < 2)
		return (1);
	current = stack_a->top;
	while (current && current->next)
	{
		if (current->index + 1 != current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
