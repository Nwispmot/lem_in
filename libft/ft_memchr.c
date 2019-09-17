/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:44:12 by hluton            #+#    #+#             */
/*   Updated: 2018/12/29 19:31:03 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	charc;
	unsigned char	*str;

	charc = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > 0)
	{
		if (charc == *str)
		{
			return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
