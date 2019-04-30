/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:24:31 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:09:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	neg;
	long long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= (long long int)10;
		num += (long long int)(str[i++] - '0');
	}
	return (num * neg);
}
