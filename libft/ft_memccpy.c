/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:22:29 by suvitiel          #+#    #+#             */
/*   Updated: 2019/01/10 03:33:27 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	unsigned char		*orig;
	unsigned char		f;
	size_t				i;

	f = (unsigned char)c;
	i = 0;
	res = (unsigned char *)dst;
	orig = (unsigned char *)src;
	while (i < n)
	{
		if (orig[i] == f)
		{
			*(res + i) = *(orig + i);
			return (res + i + 1);
		}
		else
		{
			*(res + i) = *(orig + i);
			i++;
		}
	}
	return (NULL);
}
