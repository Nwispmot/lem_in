/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:08:05 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:33:09 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			delete_cross(t_lem *lem)
{
	char	**split;

	split = ft_strsplit(lem->cross_rooms, ' ');
	delete_connection(split[0], find_room_by_name(split[1], &lem));
	delete_connection(split[1], find_room_by_name(split[0], &lem));
	lem->is_cross_found = 0;
	free_str_point(split);
}

void			reverse_path(int index, t_lem *lem)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_strsplit(lem->pathes[index], ' ');
	ft_strdel(&lem->pathes[index]);
	while (split[i])
		i++;
	i--;
	lem->pathes_lengthes[index] = i;
	lem->pathes[index] = ft_strdup(split[i]);
	i--;
	while (i >= 0)
	{
		lem->pathes[index] = ft_strjoin_free(
			lem->pathes[index], " ", 1, 0);
		lem->pathes[index] = ft_strjoin_free(
			lem->pathes[index], split[i], 1, 0);
		i--;
	}
	free_str_point(split);
}

void			reverse_pathes(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->pathes_amount)
	{
		reverse_path(i, lem);
		i++;
	}
}
