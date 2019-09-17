/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:34:50 by hluton            #+#    #+#             */
/*   Updated: 2018/12/29 19:35:30 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		src[i] = (unsigned char)(c);
		i++;
	}
	return (b);
}
