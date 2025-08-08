/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:47:55 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/08 17:20:29 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	ft_radix_sort(t_stack *b, t_stack *a)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;
	t_list	*node;

	size = a->size;

	// 1. 找最大 index 的二进制位数
	max_bits = 0;
	node = a->top;
	while (node)
	{
		if (node->index > (1 << max_bits) - 1)
			max_bits++;
		node = node->next;
	}

	// 2. 按位（从最低位到最高位）分配
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b); // 当前位是 0，推到 B
			else
				ra(a); // 当前位是 1，留在 A 末尾
			j++;
		}
		while (b->size > 0)
			pa(a, b); // 把 B 全部拉回 A
		i++;
	}
}

