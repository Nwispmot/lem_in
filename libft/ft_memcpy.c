/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:34:00 by hluton            #+#    #+#             */
/*   Updated: 2018/12/29 19:34:01 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*res;
	const char	*orig;
	size_t		i;

	i = 0;
	res = dst;
	orig = src;
	while (i < n)
	{
		*(res + i) = *(orig + i);
		i++;
	}
	return (res);
}
