/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:22:57 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/08 14:33:49 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <math.h>

typedef struct s_list
{
	int				value;
	int				index; //initalize to -1
	struct s_list	*prior;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				size;
	struct s_list	*top;
	struct s_list	*bottom;
}	t_stack;

typedef struct s_move
{
	// int index;
	int	ra;
	int	rb;
	// int	rra;
	// int	rrb;
	int	cost;
}	t_move;

//stack operations
t_stack	*ft_into_stack(char **argv);
t_stack	*ft_stack_init(void);
t_list	*ft_lstnew_ps(long input);
void	ft_lstadd_back_ps(t_stack *stack, t_list *new_node);
void	free_stack(t_stack *stack);


// push_swap operations
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//// input check
char	**ft_split_ps(char const *s, char c);
long	ft_atoi_ps(char *str);

// sorting
void	ft_sorting_three(t_stack *stack_a);
void	ft_sorting_small(t_stack *stack_a, t_stack *stack_b);
void	ft_get_stack_index(t_stack *stack_a);
int		ft_is_sorted(t_stack *stack_a);
void	ft_pull(t_stack *a, t_stack *b);
void	reconsider(t_stack *a, t_stack *b, t_list *node);
void	ft_radix_sort(t_stack *b, t_stack *a);


void	ft_reverse_radix_pull(t_stack *a, t_stack *b);

#endif
