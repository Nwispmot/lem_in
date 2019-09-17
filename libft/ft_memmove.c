/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:39:10 by hluton            #+#    #+#             */
/*   Updated: 2018/12/20 19:44:40 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*orig;
	size_t			i;

	i = 0;
	res = (unsigned char *)dst;
	orig = (unsigned char *)src;
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			*(res + n) = *(orig + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(res + i) = *(orig + i);
			i++;
		}
	}
	return (res);
}
