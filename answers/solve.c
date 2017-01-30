/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:10:00 by mburson           #+#    #+#             */
/*   Updated: 2016/12/10 12:10:01 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char			**malloc_solution_map(int size)
{
	char	**solution;
	int		i;

	if (!(solution = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(solution[i] = (char*)malloc(sizeof(char) * size)))
		{
			free_n_pointers((void**)solution, i, sizeof(char*));
			free(solution);
			return (NULL);
		}
		i++;
	}
	return (solution);
}

static char		**init_solution(char **solution, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			solution[y][x] = '.';
			x++;
		}
		y++;
	}
	return (solution);
}

static char		**solve_size(void)
{
	char	**solution;

	if (!(solution = malloc_solution_map(g_map_size)))
	{
		return (NULL);
	}
	init_solution(solution, g_map_size);
	solution = recursion_head(solution, 0);
	return (solution);
}

static	int		min_solution_size(int len)
{
	int	i;

	i = 1;
	while (len * 4 > i * i)
		i++;
	return (i);
}

char			**solve(void)
{
	char	**solution;
	int		input_len;

	input_len = 0;
	while (g_input[input_len] != -1)
		input_len++;
	g_map_size = min_solution_size(input_len);
	while (!(solution = solve_size()))
		g_map_size++;
	return (solution);
}
