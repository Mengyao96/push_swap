/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:02:40 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/02 23:47:41 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_sorting_three(t_stack *stack_a)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (!stack_a || stack_a->size > 3)
		return (0);
	a = stack_a->top;
	b = a->next;
	if (a->value > b->value)
		sa(stack_a);
	c = b->next;
	if (!c)
		return (1);
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
	return (1);
}

t_list	*find_min(t_stack *stack_a, int *index)
{
	int		min_value;
	t_list	*current;
	t_list	*min_node;

	if (!stack_a || stack_a->size == 0)
		return (NULL);
	current = stack_a->top;
	min_value = current->value;
	while (current)
	{
		if (current->value <= min_value)
		{
			min_value = current->value;
			min_node = current;
		}
		current = current->next;
		*index++;
	}
	return (min_node);
}

int	ft_sorting_small(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min_node;
	int		index;

	if (!stack_a || stack_a->size > 5)
		return (0);
	if (stack_a->size <= 3)
	{
		ft_sorting_three(stack_a);
		if (stack_b->size == 0)
			return (1);
	}
	min_node = find_min(stack_a, &index);
	if (index < 3 && index - 1 >= 0)
		ra(stack_a);
	else if (index >= 3)
		rra(stack_a);
	while (stack_a->size > 3)
		pb(stack_a, stack_b);
	ft_sorting_three(stack_a);
	while (stack_b->top->value < stack_a->top->value)
		pa(stack_a, stack_b);
	if (stack_b->top->value > stack_a->bottom->value)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
	else
		pa(stack_a, stack_b);

}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_list	*current;
	int 	check;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);

	stack_a = ft_into_stack(argv);
	if (!stack_a)
		return (ft_printf("Error\n"), 0);

	// current = stack_a->top;
	// while (current)
	// {
	// 	ft_printf("stack_a:\n%d\n", current->value);
	// 	current = current->next;
	// }

	if (stack_a->size == 3)
		check = ft_sorting_three(stack_a);
	if (stack_a->size == 5)
		check = ft_sorting_five(stack_a, stack_b);
	if (check == 0)
		return (ft_printf("Error here\n"), 0);

	free_stack(stack_a);
	return (0);
}
