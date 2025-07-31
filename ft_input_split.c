/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:45:48 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/30 22:24:24 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_substr(char const *s, char c)
{
	size_t	count;
	int		check;
	size_t	i;

	count = 0;
	check = 0;
	i = 0;
	if (s[0] == ' ')
		return (0);
	while (s[i])
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			count++;
		}
		else if (s[i] == c)
		{
			if (s[i + 1] == c)
				return (0);
			check = 0;
		}
		i++;
	}
	return (count);
}

static size_t	substr_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*get_substr(const char *s, char c)
{
	char	*substr;
	size_t	j;
	size_t	len;

	len = substr_len(s, c);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	j = 0;
	while (s[j] && j < len)
	{
		substr[j] = s[j];
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

static void	*free_rest(char **arr, int i)
{
	if (!arr[i])
	{
		while (i--)
		{
			free(arr[i]);
		}
		free(arr);
		return (NULL);
	}
	else
		return (arr[i]);
}

char	**ft_split_ps(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s || count_substr(s, c) == 0)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			ptr[i] = get_substr(s, c);
			if (!ptr[i])
				return (free_rest(ptr, i), NULL);
			s = s + substr_len(s, c);
			i++;
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}
