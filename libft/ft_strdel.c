/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:00:42 by hluton            #+#    #+#             */
/*   Updated: 2019/07/01 19:58:49 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return (0);
}
