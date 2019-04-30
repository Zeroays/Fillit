/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:32:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:08:19 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intnew(size_t size)
{
	int *int_arr;

	if (!(size >= 1))
		return (NULL);
	if (!(int_arr = (int *)malloc(size * sizeof(int))))
		return (NULL);
	return (int_arr);
}
