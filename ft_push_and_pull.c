/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_pull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:47:55 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/08 18:18:56 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

t_list	*get_max_node(t_stack *stack)
{
	t_list	*curr;
	t_list	*max_node;

	if (!stack || stack->size == 0)
		return (NULL);
	curr = stack->top;
	max_node = curr;
	while (curr)
	{
		if (curr->index > max_node->index)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}


/* void	ft_greedy_push(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	lbound;
	int	max;
	int	count;
	t_list	*curr;

	chunk_size = sqrt(a->size);
	printf("chunk size: %d\n", chunk_size);
	lbound = 0;
	max = a->size;
	count = 0;
	while (a->size > 3)
	{
		if (a->top->index >= max - 3)
			ra(a);
		if (a->top->index >= lbound && a->top->index <= lbound + chunk_size)
		{
			pb(a, b);
			printf("pb %d\n", b->top->index);
			count++;
			if (b->size > 1 && b->top->index < b->top->next->index)
			{
				rb(b);
			}
		}
		else
		{
			printf("ra %d\n", a->top->index);
			ra(a);
		}
		if (b->top && b->top->index == lbound + chunk_size)
			lbound += 1;
	}
	printf("sort three\n");
	ft_sorting_three(a);
} */


void	ft_greedy_push(t_stack *a, t_stack *b)
{
	int	padding;
	int	i;

	padding = a->size / 23/* sqrt(a->size) */;
	i = 0;
	while (a->size > 0)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if(a->top->index <= i + padding)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}


void	node_pos(t_stack *a, t_stack *b, t_list *node, int location[2], int *op_cost)
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

	node_pos(a, b, node, pos, &op_cost);
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

void	ex_rotate(t_stack *a, t_stack *b, t_list *cheapest)
{
	t_move	moves;

	move_cost(a, b, cheapest, &moves);
	while (a->bottom->index < a->bottom->prior->index && a->bottom->index > cheapest->index)
	{
		rra(a);
	}
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
	// reconsider(a, b, cheapest);
	printf("stratigh %d to pa\n", b->top->index);
	pa(a, b);
}


void	reconsider(t_stack *a, t_stack *b, t_list *cheapest)
{
	t_move	moves;

	move_cost(a, b, cheapest, &moves);
	if (a->size != 3 && a->top->index > a->bottom->index && (a->bottom->index > cheapest->index))
	{
		// && (a->bottom->index > cheapest->index))
		rra(a);
	}
	else if (a->top->index < a->bottom->index)
	{
		if (a->top->index - 1 != b->top->index)
		{
			cheapest = get_max_node(b);
			ex_rotate(a, b, cheapest);
		}
	}


}

// void	ft_pull(t_stack *a, t_stack *b)
// {
// 	t_move	moves;
// 	t_list	*cheapest;

// 	if (b->size == 0) //!!!!
// 		return;

// 	cheapest = get_cheapest_node(a, b);
// 	move_cost(a, b, cheapest, &moves);
// 	ex_rotate(a, b, cheapest);
// 	printf("finishing: %d\nnext round:\n", a->top->index);
// 	ft_pull(a, b);

// 	// while (!ft_is_sorted(a))
// 	// {
// 	// 	resorting
// 	// }

// }

int get_moves(t_list *node, int index)
{
	int	moves;

	moves = 0;
	while (node != NULL)
	{
		if (node->index == index)
			break;
		moves++;
		node = node->next;
	}
	return (moves);
}

void	ft_pull(t_stack *a, t_stack *b)
{
	int moves;
	int moves_rev;

	while (b->size > 0)
	{
		moves = get_moves(b->top, b->size - 1);
		moves_rev = b->size - moves;
		if (moves <= moves_rev)
		{
			while (moves > 0)
			{
				rb(b);
				moves--;
			}
		}
		else
		{
			while (moves_rev > 0)
			{
				rrb(b);
				moves_rev--;
			}
		}
		pa(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_list	*current;
	// int 	check;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	a = ft_into_stack(argv);
	if (!a)
		return (ft_printf("Error\n"), 0);
	b = ft_stack_init();

	ft_get_stack_index(a);
	if (!a || a->size <= 3)
		return (ft_sorting_three(a), 0);

	ft_greedy_push(a, b);
	ft_pull(a, b);
	// ft_radix_sort(a, b);

	free_stack(a);
	free_stack(b);
	return (0);
}
