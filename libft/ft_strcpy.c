/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:45:00 by hluton            #+#    #+#             */
/*   Updated: 2018/12/13 16:26:16 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned char	*orig;
	unsigned char	*res;

	orig = (unsigned char *)src;
	res = (unsigned char *)dest;
	while (*orig)
		*(res++) = *(orig++);
	*res = '\0';
	return (dest);
}
