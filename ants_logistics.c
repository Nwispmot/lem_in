/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_logistics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:25:00 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:28:47 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int			count_logistics_time(t_lem *lem)
{
	int		i;
	int		min_time;
	int		best_logistics_index;

	min_time = 0;
	i = 0;
	lem->logistics_time = ft_memalloc(sizeof(int) * lem->pathes_amount);
	while (i < lem->pathes_amount)
	{
		lem->logistics_time[i] = count_cur_time(lem->ants_logistics[i], lem);
		if (min_time == 0)
			min_time = lem->logistics_time[i];
		if (lem->logistics_time[i] < min_time)
		{
			best_logistics_index = i;
			min_time = lem->logistics_time[i];
		}
		i++;
	}
	return (best_logistics_index);
}

void		free_ants_logistics(t_lem *lem)
{
	int		i;

	i = 2;
	lem->ants_logistics[1] = 0;
	while (lem->ants_logistics[i])
	{
		free(lem->ants_logistics[i]);
		i++;
	}
}

void		ants_logistics_3(t_lem *lem)
{
	free_ants_logistics(lem);
	lem->ants_logistics[0] = &lem->ants_amount;
	free_pathes(lem);
	lem->pathes[0] = lem->shortest_way;
	lem->best_logistics_index = 0;
	reverse_path(0, lem);
}

void		ants_logistics(t_lem *lem)
{
	int		ants_per_path;
	int		ants_remainder;
	int		pathes_amount;
	int		shortest_time;

	pathes_amount = 1;
	while (pathes_amount <= lem->pathes_amount)
	{
		ants_per_path = lem->ants_amount / pathes_amount;
		write_ants_to_logistics(ants_per_path, pathes_amount, lem);
		ants_remainder = lem->ants_amount % pathes_amount;
		write_remainder_to_logistics(ants_remainder, pathes_amount, lem);
		pathes_amount++;
	}
	lem->best_logistics_index = count_logistics_time(lem);
	shortest_time = lem->ants_amount - 2 + lem->shortest_way_length;
	if (lem->logistics_time[lem->best_logistics_index] < shortest_time)
		return ;
	else
	{
		ants_logistics_3(lem);
		return ;
	}
}
