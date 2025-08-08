/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_pull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:47:55 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/08 02:21:27 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	ft_greedy_push(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	ubound;
	int	lbound;
	int	max;
	int	round;

	chunk_size = a->size ^ (1 / 2);
	lbound = round % (a->size / chunk_size) * chunk_size;
	ubound = lbound + chunk_size;
	max = a->size;
	while (a->size > 3)
	{
		if (a->top->index >= max - 3)
			ra(a);
		else if (a->top->index >= lbound && a->top->index <= ubound)
			pb(a, b);
		else
			ra(a);
		if (b->top && b->top->index == ubound)
			lbound += 1;
	}
	ft_sorting_three(a);
}

void	location_node(t_stack *a, t_stack *b, t_list *node, int location[2], int *op_cost)
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
		{
			*op_cost = current->index - node->index - 1;
			break;
		}
		current = current->next;
		location[1]++;
	}
	return;
}

void	move_cost(t_stack *a, t_stack *b, t_list *node, t_move *moves)
{
	int		pos[2];
	int		op_cost;

	location_node(a, b, node, pos, &op_cost);
	if (pos[0] <= b->size / 2)
		moves->rb = pos[0];
	else
		moves->rb = pos[0] - b->size;
	if (pos[1] <= a->size / 2)
		moves->ra = pos[1];
	else
		moves->ra = pos[1] - a->size;
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
	moves->cost = moves->cost + op_cost;
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

void	ex_rotate(t_stack *a, t_stack *b, t_move *moves)
{
	while (moves->rb > 0 || moves->ra > 0)
	{
		if (moves->ra > 0 && moves->rb > 0)
		{
			rr(a, b);
			moves->ra--;
			moves->rb--;
		}
		else if (moves->rb > 0)
		{
			rb(b);
			moves->rb--;
		}
		else if (moves->ra > 0)
		{
			ra(a);
			moves->ra--;
		}
	}
	while (moves->rb < 0)
	{
		rrb(b);
		moves->rb++;
	}
	reconsider(a, b, moves);
}

void	reconsider(t_stack *a, t_stack *b, t_move *moves) // atop, abottom, btop
{

	// printf("reconsder: %d \n", b->top->index);
	if (a->size != 3 && a->top->index > a->bottom->index && (a->bottom->index > b->top->index)) //bottom-up recycle ++
	{
		rra(a);
	}
	else if (a->top->index < a->bottom->index) // at this moment, already:: && (a->top->index < b->top->index)
	{
		// printf("moves->ra: %d, moves->rb: %d\n", moves->ra, moves->rb);
		while (moves->ra > 0)
		{
			ra(a);
			moves->ra--;
		}
		// while (moves->ra < 0)
		// {
		// 	rra(a);
		// 	moves->ra++;
		// }
	}
	// printf("stratigh %d to pa\n", b->top->index);
	pa(a, b);
	while (!(a->bottom->index > a->bottom->prior->index))
	{
		rra(a);
	}
}

void	ft_pull(t_stack *a, t_stack *b)
{
	t_move	moves;
	t_list	*cheapest;

	if (b->size == 0 && ft_is_sorted(a) == 1) //
		return;

	cheapest = get_cheapest_node(a, b);
	move_cost(a, b, cheapest, &moves);
	ex_rotate(a, b, &moves);
	// printf("finishing: %d\n then next round:\n", a->top->index);
	ft_pull(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_list	*current;
	// int 	check;

	a = NULL;
	b = ft_stack_init();
	if (argc < 2 || argv[1][0] == '\0')
		return (0);

	a = ft_into_stack(argv);
	if (!a)
		return (ft_printf("Error\n"), 0);
	ft_get_stack_index(a);
	if (!a || a->size <= 3)
		return (ft_sorting_three(a), 0);

	ft_greedy_push(a, b);
	ft_pull(a, b);


	free_stack(a);
	return (0);
}
