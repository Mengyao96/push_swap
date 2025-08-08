/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:30:44 by mezhang           #+#    #+#             */
/*   Updated: 2025/08/08 16:12:56 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**str_check_split(char *argv_str)
{
	char	**arry;
	size_t	i;
	size_t	len;

	if (!argv_str || !*argv_str)
		return (NULL);
	arry = ft_split_ps(argv_str, ' ');
	if (!arry || !*arry)
		return (NULL);
	i = 0;
	while (arry[i])
	{
		len = ft_strlen(arry[i]);
		if (ft_atoi_ps(arry[i]) == 0 && !((len == 1 && arry[i][0] == '0')
			|| (len == 2 && (arry[i][0] == '-' || arry[i][0] == '+')
			&& arry[i][1] == '0')))
		{
			return (free_array(arry), NULL);
		}
		i++;
	}
	return (arry);
}

static char	**get_legit_arry(char **argv)
{
	char	*joined;
	char	*temp;
	char	*temp_space;
	char	**result;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (*++argv)
	{
		if (str_check_split(*argv) == NULL)
			return (free(joined), NULL);
		temp = ft_strjoin(joined, *argv);
		if (!temp)
			return (free(joined), NULL);
		temp_space = ft_strjoin(temp, " ");
		free(temp);
		if (!temp_space)
			return (free(temp), free(joined), NULL);
		free(joined);
		joined = temp_space;
	}
	result = str_check_split(joined);
	free(joined);
	return (result);
}

#include <stdio.h>

//check for eligibility of inputs
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	if (argc < 2)
// 		return (0);
// 	// char	**legit_arry = str_check_split(*++argv);
// 	char	**legit_arry = get_legit_arry(argv);
// 	if (!legit_arry)
// 		return (printf("Error\n"), 0);
// 	while (*legit_arry)
// 	{
// 		printf("%s\n", *legit_arry);
// 		legit_arry++;
// 	}
// 	return (0);
// }

static int	ft_dbdigit_check(char **result)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (result[i])
	{
		temp = ft_atoi_ps(result[i]);
		j = i + 1;
		while (result[j])
		{
			if (temp == ft_atoi_ps(result[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// make inputs eligile for stack_a
t_stack	*ft_into_stack(char **argv)
{
	t_stack	*stack_a;
	int		i;
	t_list	*new_node;
	char	**legit_arry;

	stack_a = ft_stack_init();
	legit_arry = get_legit_arry(argv);
	if (legit_arry == NULL || ft_dbdigit_check(legit_arry) == 0)
		return (NULL);
	i = 0;
	while (legit_arry[i])
	{
		new_node = ft_lstnew_ps(ft_atoi_ps(legit_arry[i]));
		if (!new_node)
			return (free_stack(stack_a), NULL);
		ft_lstadd_back_ps(stack_a, new_node);
		i++;
	}
	free_array(legit_arry);
	return (stack_a);
}
/*
int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*current;

	if (argc < 2)
		return (0);

	stack = ft_into_stack(argv);
	if (!stack)
		return (printf("Error\n"), 0);

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	free_stack(stack);
	return (0);
} */
