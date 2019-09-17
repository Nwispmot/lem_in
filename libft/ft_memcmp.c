/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:45:38 by hluton            #+#    #+#             */
/*   Updated: 2019/01/10 03:50:03 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	if (len == 0)
		return (0);
	while (--len)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return (*s1 - *s2);
}
