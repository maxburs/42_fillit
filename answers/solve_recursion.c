/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_recursion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:34:36 by mburson           #+#    #+#             */
/*   Updated: 2016/12/10 12:10:14 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fillit.h>

#include <stdio.h>

static _Bool	does_fit(char **map, int piece, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (map_mask(map, g_mp, x + g_p_crds_y[piece][i],\
				y + g_p_crds_x[piece][i]) != '.')
			return (0);
		i++;
	}
	return (1);
}

static void		remove_piece(char **solution, int step, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		solution[y + g_p_crds_x[g_input[step]][i]][x\
			+ g_p_crds_y[g_input[step]][i]] = '.';
		i++;
	}
}

static void		add_piece(char **solution, int step, int x, int y)
{
	int		i;
	char	c;

	c = 'A' + step;
	i = 0;
	while (i < 4)
	{
		solution[y + g_p_crds_x[g_input[step]][i]][x\
			+ g_p_crds_y[g_input[step]][i]] = c;
		i++;
	}
}

int				recursion_head(char **solution, int step)
{
	int		x;
	int		y;

	//print_map(solution);
	if (g_input[step] == -1)
		return (1);
	y = 0;
	while (y < g_mp)
	{
		x = 0;
		while (x < g_mp)
		{
			if (does_fit(solution, g_input[step], x, y))
			{
				//printf("piece %d fits\n", step);
				add_piece(solution, step, x, y);
				if (recursion_head(solution, step + 1))
					return (1);
				remove_piece(solution, step, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
