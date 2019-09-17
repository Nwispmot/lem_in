/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:36:59 by hluton            #+#    #+#             */
/*   Updated: 2019/01/10 04:57:35 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *d;

	d = (char *)s;
	if ((char)c == '\0')
		return (d + ft_strlen(s));
	while (*d)
	{
		if ((char)c == *d)
			return (d);
		d++;
	}
	return (NULL);
}
