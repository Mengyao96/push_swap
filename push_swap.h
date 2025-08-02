/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:22:57 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/02 21:16:09 by mezhang          ###   ########.fr       */
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

typedef struct s_list
{
	int				value;
	struct s_list	*prior;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				size;
	struct s_list	*top;
	struct s_list	*bottom;
}	t_stack;

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
int		ft_sorting_three(t_stack *stack_a);


#endif
