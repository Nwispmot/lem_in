/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:34:24 by hluton            #+#    #+#             */
/*   Updated: 2018/12/26 00:19:14 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(str);
	if (!(str2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);
}
