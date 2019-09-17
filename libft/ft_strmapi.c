/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:31:55 by hluton            #+#    #+#             */
/*   Updated: 2018/12/22 23:37:10 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))))
	{
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
