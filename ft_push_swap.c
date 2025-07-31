/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:28:04 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/31 18:09:49 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	// t_stack	*stack_b = NULL;
	char	*commands;

	// input check。 if == 2， it's working too
	if (argc < 2 || argv[1][0] == '\0')
		return (0);

	//inputs eligibility check & establish the stack_a
	stack_a = ft_int_to_stack(argv);
	if (!stack_a)
		return (ft_printf("Error\n"), 0);

	// record all the commands into a char
	commands = ft_sorting(stack_a);
	if (!commands)
		return (ft_printf("Error\n"), 0);

	// print out all commmands and clean up
	ft_final_print("%s", commands);
	free(commands);
	free_stack(&stack_a);
	return (0);
}
