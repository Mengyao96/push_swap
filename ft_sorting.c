/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:31:21 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/03 20:39:39 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size <= 3)
	{
		ft_sorting_three(stack_a);
		return ;
	}

}






void	ft_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		return ;
	// Implement sorting logic here
	// This is a placeholder for the actual sorting algorithm
	// You can use various algorithms like bubble sort, quicksort, etc.
	// depending on the requirements and constraints of your project.
}
