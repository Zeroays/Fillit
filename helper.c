/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:33:37 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:05:06 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	arfr(void **arr, size_t rows, int dp)
{
	size_t i;

	i = 0;
	while (i < rows)
	{
		ft_memdel((void **)(&arr[i]));
		i++;
	}
	(dp) ? free(arr) : dp;
}

void	tris_del(t_tris *tetriminos)
{
	t_tris *tmp;

	while (tetriminos)
	{
		tmp = tetriminos;
		tetriminos = tetriminos->next;
		arfr((void **)(tmp->cor), TET_SIZE, 1);
		free(tmp);
	}
}

t_tris	*tris_new(int *t[], int ltr, size_t rows, size_t cols)
{
	t_tris *tetris;
	size_t i;

	i = 0;
	if (!(tetris = (t_tris *)malloc(sizeof(t_tris))))
		return (NULL);
	if ((!((tetris->cor) = (int **)malloc(sizeof(int *) * rows))))
	{
		free(tetris);
		return (NULL);
	}
	while (i < rows)
	{
		if (!((tetris->cor)[i] = (int *)malloc(sizeof(int) * cols)))
		{
			arfr((void **)tetris->cor, i, 1);
			free(tetris);
			return (NULL);
		}
		ft_memcpy((tetris->cor)[i], t[i], cols * sizeof(int));
		i++;
	}
	tetris->next = NULL;
	tetris->letter = ltr;
	return (tetris);
}

int		tris_size(t_tris *tetriminos)
{
	t_tris *tmp;
	size_t size;

	size = 0;
	tmp = tetriminos;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
