/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:45:40 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:42:09 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**tris_normalize(int *t[])
{
	size_t	index;
	int		min_x;
	int		min_y;

	index = 0;
	min_x = TET_SIZE;
	min_y = TET_SIZE;
	while (index < TET_SIZE)
	{
		if (t[index][0] < min_x)
			min_x = t[index][0];
		if (t[index][1] < min_y)
			min_y = t[index][1];
		index++;
	}
	while (index--)
	{
		t[index][0] -= min_x;
		t[index][1] -= min_y;
	}
	return (t);
}

t_tris	*tstore(char *piece[], int *t[], int status)
{
	static t_tris	*alst;
	t_tris			*tmp;

	if (status == -1)
	{
		(t == NULL) ? arfr((void **)t, TET_SIZE, 0) : t;
		fillit_exit(3);
	}
	if (!(alst))
	{
		alst = tris_new(tris_normalize(t), tris_size(alst) + 'A', TET_SIZE, 2);
		arfr((void **)t, TET_SIZE, 0);
		arfr((void **)piece, TET_SIZE, 0);
		return (alst);
	}
	tmp = alst;
	arfr((void **)piece, TET_SIZE, 0);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tris_new(tris_normalize(t), tris_size(alst) + 'A', TET_SIZE, 2);
	arfr((void **)t, TET_SIZE, 0);
	return (alst);
}

int		**tris_shift(int **t, int i, int j)
{
	size_t	index;
	int		**tmp;

	index = 0;
	tmp = (int **)malloc(sizeof(int *) * TET_SIZE);
	while (index < TET_SIZE)
		tmp[index++] = ft_intnew(2);
	index = 0;
	while (index < TET_SIZE)
	{
		tmp[index][0] = t[index][0] + i;
		tmp[index][1] = t[index][1] + j;
		index++;
	}
	return (tmp);
}
