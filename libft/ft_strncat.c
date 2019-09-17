/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:25:43 by hluton            #+#    #+#             */
/*   Updated: 2018/12/13 18:33:39 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t k;

	k = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[k] && n--)
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (dest);
}
