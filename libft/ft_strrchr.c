/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 00:31:28 by hluton            #+#    #+#             */
/*   Updated: 2019/01/10 04:58:52 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;
	char	*last;
	int		flag;

	flag = 0;
	d = (char *)s;
	if ((char)c == '\0')
		return (d + ft_strlen(s));
	while (*d)
	{
		if ((char)c == *d)
		{
			last = d;
			flag = 1;
		}
		d++;
	}
	if (flag)
		return (last);
	return (NULL);
}
