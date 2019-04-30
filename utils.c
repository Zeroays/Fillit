/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:27:42 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:24:43 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**square_grid(size_t n)
{
	size_t	i;
	size_t	j;
	int		**grid;

	i = 0;
	if (!(grid = (int **)malloc(sizeof(int *) * n)))
		return (NULL);
	while (i < n)
	{
		if (!(grid[i] = (int *)malloc(sizeof(int) * n)))
		{
			arfr((void **)grid, i, 1);
			return (NULL);
		}
		j = 0;
		while (j < n)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

size_t	smallest_square(size_t t_num)
{
	size_t	i;
	size_t	tot_parts;

	i = 1;
	tot_parts = t_num * TET_SIZE;
	while ((i * i) < tot_parts)
		i++;
	return (i);
}

int		hit(int **t_cor, int **grid, size_t g_size)
{
	int		i;

	i = 0;
	while (i < TET_SIZE)
	{
		if ((t_cor[i][0] >= (int)g_size) || (t_cor[i][1] >= (int)g_size))
			return (INVALID_INDEX);
		else if ((grid[t_cor[i][0]][t_cor[i][1]] >= 'A') \
				&& (grid[t_cor[i][0]][t_cor[i][1]] <= 'Z'))
			return (FILLED);
		i++;
	}
	return (0);
}

void	print_grid(int **grid, size_t g_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
