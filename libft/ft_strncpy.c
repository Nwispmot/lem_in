/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:02:25 by hluton            #+#    #+#             */
/*   Updated: 2019/07/01 21:30:34 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned char	*orig;
	unsigned char	*res;

	orig = (unsigned char *)src;
	res = (unsigned char *)dest;
	while (n && *orig)
	{
		*(res++) = *(orig++);
		n--;
	}
	while (n-- > 0)
		*(res++) = '\0';
	return (dest);
}
