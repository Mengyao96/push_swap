/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:28:04 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/02 18:33:48 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	char	*commands;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (argc < 2 || argv[1][0] == '\0')
// 		return (0);

// 	//inputs eligibility check & establish the stack_a
// 	stack_a = ft_into_stack(argv);
// 	if (!stack_a)
// 		return (ft_printf("Error\n"), 0);

// 	// record all the commands into a char
// 	commands = ft_sorting(stack_a);
// 	if (!commands)
// 		return (ft_printf("Error\n"), 0);

// 	// print out all commmands and clean up
// 	ft_final_print("%s", commands);
// 	free(commands);
// 	free_stack(&stack_a);
// 	return (0);
// }
