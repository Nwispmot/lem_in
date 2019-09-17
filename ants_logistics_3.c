/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_logistics_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:29:05 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:29:35 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		write_remainder_to_logistics(int ants_remainder, int i, t_lem *lem)
{
	int		j;

	j = 0;
	while (ants_remainder--)
	{
		lem->ants_logistics[i - 1][j] += 1;
		j++;
	}
}

int			count_cur_time(int *ants_logistics, t_lem *lem)
{
	int		i;
	int		time;
	int		max_time;

	max_time = 0;
	time = 0;
	i = 0;
	while (ants_logistics[i])
	{
		time = ants_logistics[i] - 2 + lem->pathes_lengthes[i];
		if (time > max_time)
			max_time = time;
		i++;
	}
	return (max_time);
}
