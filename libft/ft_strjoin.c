/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:58:30 by hluton            #+#    #+#             */
/*   Updated: 2019/07/06 15:28:33 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if ((fresh = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		{
			ft_strcpy(fresh, s1);
			ft_strcpy(fresh + ft_strlen(s1), s2);
			return (fresh);
		}
	}
	return (NULL);
}
