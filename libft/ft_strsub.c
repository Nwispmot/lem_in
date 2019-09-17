/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:46:52 by hluton            #+#    #+#             */
/*   Updated: 2018/12/22 23:56:57 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s)
	{
		if ((fresh = ft_strnew(len)))
		{
			while (s[start + i] && len--)
			{
				fresh[i] = s[start + i];
				i++;
			}
			return (fresh);
		}
	}
	return (NULL);
}
