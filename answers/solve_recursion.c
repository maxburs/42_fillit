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
#include <unistd.h>

static _Bool	does_fit(char **map, int piece, int x, int y)
{
	if (map_mask(map, g_mp, x + g_p_crds_y[piece][0],\
			y + g_p_crds_x[piece][0]) != '.')
		return (0);
	else if (map_mask(map, g_mp, x + g_p_crds_y[piece][1],\
			y + g_p_crds_x[piece][1]) != '.')
		return (0);
	else if (map_mask(map, g_mp, x + g_p_crds_y[piece][2],\
			y + g_p_crds_x[piece][2]) != '.')
		return (0);
	else if (map_mask(map, g_mp, x + g_p_crds_y[piece][3],\
			y + g_p_crds_x[piece][3]) != '.')
		return (0);
	return (1);
}

static void		remove_piece(char **solution, int piece, int x, int y)
{
	solution[y + g_p_crds_x[piece][0]][x\
			+ g_p_crds_y[piece][0]] = '.';
	solution[y + g_p_crds_x[piece][1]][x\
			+ g_p_crds_y[piece][1]] = '.';
	solution[y + g_p_crds_x[piece][2]][x\
			+ g_p_crds_y[piece][2]] = '.';
	solution[y + g_p_crds_x[piece][3]][x\
			+ g_p_crds_y[piece][3]] = '.';
}

static void		add_piece(char **solution, int step, int x, int y)
{
	char	c;
	int		piece;

	c = 'A' + step;
	piece = g_input[step];
	solution[y + g_p_crds_x[piece][0]][x\
		+ g_p_crds_y[piece][0]] = c;
	solution[y + g_p_crds_x[piece][1]][x\
		+ g_p_crds_y[piece][1]] = c;
	solution[y + g_p_crds_x[piece][2]][x\
		+ g_p_crds_y[piece][2]] = c;
	solution[y + g_p_crds_x[piece][3]][x\
		+ g_p_crds_y[piece][3]] = c;
}

int				recursion_head(char **solution, int step)
{
	int		x;
	int		y;
	int		piece;

	//print_map(solution);
	//printf("piece: %d\n", g_input[step]);
	//printf("staring row: %d\n", g_farthest_y[g_input[step]]);
	//write(1, "\n", 1);
	if (g_input[step] == -1)
		return (1);
	piece = g_input[step];
	y = g_farthest_y[piece];
	//int i;
	//i = 0;
	//while (i < P_TYPE_CNT)
	//{
	//	printf("%d s=: %d, ", i,g_farthest_y[i]);
	//	i++;
	//}
	while (y < g_mp)
	{
		x = 0;
		while (x < g_mp)
		{
			if (does_fit(solution, piece, x, y))
			{
				//printf("piece %d fits\n", step);
				g_farthest_y[piece] = y;
				add_piece(solution, step, x, y);
				if (recursion_head(solution, step + 1))
					return (1);
				remove_piece(solution, piece, x, y);
			}
			x++;
		}
		y++;
	}
	g_farthest_y[piece] = 0;
	return (0);
}
