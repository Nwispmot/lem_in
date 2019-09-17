/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:48:44 by hluton            #+#    #+#             */
/*   Updated: 2019/07/01 21:03:55 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t k;

	k = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[k])
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (dest);
}
