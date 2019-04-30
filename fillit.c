/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:36:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:50:05 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_tris *t, int **grid, int i, int j)
{
	size_t	index;
	int		**t_shift;

	index = 0;
	t_shift = tris_shift(t->cor, i, j);
	while (index < TET_SIZE)
	{
		grid[t_shift[index][0]][t_shift[index][1]] = t->letter;
		index++;
	}
	arfr((void **)t_shift, TET_SIZE, 1);
}

void	reset(t_tris *t, int **grid, int i, int j)
{
	size_t	index;
	int		**t_shift;

	index = 0;
	t_shift = tris_shift(t->cor, i, j);
	while (index < TET_SIZE)
	{
		grid[t_shift[index][0]][t_shift[index][1]] = '.';
		index++;
	}
	arfr((void **)t_shift, TET_SIZE, 1);
}

int		backtracking(t_tris *t, int **grid, size_t g_size)
{
	size_t	i;
	size_t	j;
	int		**tsif;

	i = -1;
	if (t == NULL)
		return (1);
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size && (tsif = tris_shift(t->cor, i, j)))
			if (!(hit(tsif, grid, g_size)))
			{
				arfr((void **)tsif, TET_SIZE, 1);
				fillit(t, grid, i, j);
				if (backtracking(t->next, grid, g_size))
					return (1);
				reset(t, grid, i, j);
			}
			else
				arfr((void **)tsif, TET_SIZE, 1);
	}
	return (0);
}
