/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_logistics_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:34:47 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:34:58 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		write_ants_to_logistics(int ants_per_path, int i, t_lem *lem)
{
	int		j;

	j = 0;
	if (lem->ants_logistics == NULL)
		lem->ants_logistics = ft_memalloc(sizeof(int*) *
		(lem->pathes_amount) + 1);
	lem->ants_logistics[i - 1] = ft_memalloc(sizeof(int) *
	(lem->pathes_amount + 1));
	while (j < i)
	{
		lem->ants_logistics[i - 1][j] = ants_per_path;
		j++;
	}
}
