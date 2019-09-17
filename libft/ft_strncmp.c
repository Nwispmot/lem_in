/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:00:06 by hluton            #+#    #+#             */
/*   Updated: 2019/01/10 22:32:03 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *b1, const char *b2, size_t len)
{
	unsigned char *s1;
	unsigned char *s2;

	if (!len)
		return (0);
	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	len--;
	while (*s1 && *s2 && len)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		len--;
	}
	return (*s1 - *s2);
}
