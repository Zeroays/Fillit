/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:17:36 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:24:03 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_strsplitalloc(const char *s, char c)
{
	char **arr;

	if (!(s) || !(c))
		return (NULL);
	arr = ft_memalloc((ft_wrdcount(s, c) + 1) * (ft_ltrcount(s, c) \
						+ ft_wrdcount(s, c) + 1));
	return (arr);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str_arr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!(str_arr = ft_strsplitalloc(s, c)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			str_arr[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	str_arr[j] = 0;
	return (str_arr);
}
