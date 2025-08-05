/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_pull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:47:55 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/05 21:56:15 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	ft_greedy_push(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	lbound;
	int	max;

	chunk_size = a->size / 5; // 5 is the best practice
	lbound = 0;
	if (!a || a->size <= 3)
		return (ft_sorting_three(a));
	max = a->size; // reserve 3 elements for sorting later
	while (a->size > 3)
	{
		if (a->top->index >= max - 3)
			ra(a);
		if (a->top->index <= lbound)
		{
			pb(a, b);
			rb(b);
		}
		else if (a->top->index <= lbound + chunk_size)
			pb(a, b);
		else
			ra(a);
		lbound += chunk_size;
	}
	ft_sorting_three(a);
}

void	location_node(t_stack *a, t_stack *b, t_list *node, int location[2])
{
	t_list	*current;

	location[0] = 0;
	location[1] = 0;
	current = b->top;
	while (current)
	{
		if (current->index == node->index)
			break;
		current = current->next;
		location[0]++;
	}
	current = a->top;
	while (current)
	{
		if (current->index > node->index)
			break;
		current = current->next;
		location[1]++;
	}
	// printf("\nlocations: b: %d, a: %d, index: %d\n", location[0], location[1], node->index);
	return;
}

/* void	move_cost(t_stack *a, t_stack *b, t_list *node, t_move *moves)
{
	int		pos[2];

	location_node(a, b, node, pos);
	if (pos[0] <= b->size / 2 && pos[1] <= a->size / 2)
	{
		moves->rb = pos[0];
		moves->ra = pos[1];
	}
	else if (pos[0] > b->size / 2 && pos[1] <= a->size / 2)
	{
		moves->rb = pos[0] - b->size; // actually the steps of rrb. but here only present the steps of rb
		moves->ra = pos[1];
	}
	else if (pos[0] <= b->size / 2 && pos[1] > a->size / 2)
	{
		moves->rb = pos[0];
		moves->ra = pos[1] - a->size; // no need to recover
	}
	else
	{
		moves->rb = pos[0] - b->size; // actually the steps of rrb. but here only present the steps of rb
		moves->ra = pos[1] - a->size; // no need to recover
	}
	moves->cost = moves->rb + moves->ra;
} */


void	move_cost(t_stack *a, t_stack *b, t_list *node, t_move *moves)
{
	int		pos[2];

	location_node(a, b, node, pos);
	if (pos[0] <= b->size / 2)
		moves->rb = pos[0];
	else
		moves->rb = pos[0] - b->size; // actually the steps of rrb. but here only present the steps of rb
	if (pos[1] <= a->size / 2)
		moves->ra = pos[1];
	else
		moves->ra = pos[1] - a->size; // no need to recover


	if (moves->rb < 0 && moves->ra >= 0)
		moves->cost = moves->rb * -1 + moves->ra;
	if (moves->rb < 0 && moves->ra <= moves->rb)
		moves->cost = moves->ra * -1;
	if (moves->rb < 0 && moves->ra < 0 && moves->rb <= moves->ra)
		moves->cost = moves->rb * -1;
	if (moves->rb >= 0 && moves->ra < 0)
		moves->cost = moves->ra * -1 + moves->rb;
	if (moves->rb >= 0 && moves->ra >= moves->rb)
		moves->cost = moves->ra;
	if (moves->rb >= 0 && moves->ra >= 0 && moves->rb >= moves->ra)
		moves->cost = moves->rb;

	// printf("\nlocations: b: %d, a: %d, index: %d, rb: %d, ra: %d, cost: %d\n",
	// 	pos[0], pos[1], node->index, moves->rb, moves->ra, moves->cost);
	// if (moves->ra >= 0 && moves->rb >= 0)
	// {
	// 	if (moves->ra >= moves->rb)
	// 		moves->cost = moves->ra;
	// 	else
	// 		moves->cost = moves->rb;
	// }
}

t_list	*get_cheapest_node(t_stack *a, t_stack *b)
{
	t_move	moves;
	int		min_steps;
	t_list	*cheapest;
	t_list	*current;

	if (!b || b->size == 0)
	return (NULL);
	current = b->top;
	min_steps = INT_MAX;
	while (current)
	{
		move_cost(a, b, current, &moves);
		if (moves.cost < min_steps)
		{
			min_steps = moves.cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}


void	ft_pull(t_stack *a, t_stack *b)
{
	t_move	moves;
	t_list	*cheapest;

	if (b->size == 0)
		return;
	cheapest = get_cheapest_node(a, b);
	move_cost(a, b, cheapest, &moves);

	while (moves.rb > 0 || moves.ra > 0)
	{
		if (moves.ra > 0 && moves.rb > 0)
		{
			rr(a, b);
			moves.ra--;
			moves.rb--;
		}
		else if (moves.rb > 0)
		{
			rb(b);
			moves.rb--;
		}
		else if (moves.ra > 0)
		{
			ra(a);
			moves.ra--;
		}
	}
	while (moves.rb < 0)
	{
		rrb(b);
		moves.rb++;
	}
	pa(a, b);
	ft_pull(a, b);
}


int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*current;
	// int 	check;

	stack_a = NULL;
	stack_b = ft_stack_init();
	if (argc < 2 || argv[1][0] == '\0')
		return (0);

	stack_a = ft_into_stack(argv);
	if (!stack_a)
		return (ft_printf("Error\n"), 0);

	ft_get_stack_index(stack_a);

	// while (ft_is_sorted(stack_a) == 0)
	// {
	// 	// ft_triple_push(stack_a, stack_b);
	// 	ft_greedy_push(stack_a, stack_b);
	// 	ft_pull(stack_a, stack_b);
	// }

	ft_greedy_push(stack_a, stack_b);
	ft_pull(stack_a, stack_b);

	// ft_sorting_small(stack_a, stack_b);

	free_stack(stack_a);
	return (0);
}
