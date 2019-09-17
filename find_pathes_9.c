/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:45:43 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 19:46:31 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				collect_shortest_way_copy(t_lem *lem)
{
	t_room	*room;

	room = find_room_copy_by_name(lem->end, &lem);
	lem->pathes_i++;
	if (!lem->pathes)
		lem->pathes = ft_memalloc(sizeof(char*) * (PATHES_SIZE + 1));
	check_pathes_buffer(lem, lem->pathes_i);
	if (get_lower_lvl_copy_room(lem))
	{
		lem->pathes_amount++;
		return (1);
	}
	return (0);
}

char			*collect_shortest_way(t_lem *lem)
{
	int		path_size;
	t_room	*room;

	room = find_room_by_name(lem->end, &lem);
	lem->pathes_i = 0;
	path_size = room->lvl;
	if (!lem->pathes)
		lem->pathes = ft_memalloc(sizeof(char*) * (PATHES_SIZE + 1));
	check_pathes_buffer(lem, lem->pathes_i);
	while (room->is_start != 1)
	{
		write_room_to_path(room->name, &lem->pathes[lem->pathes_i]);
		lem->pathes_lengthes[0]++;
		room = get_lower_lvl_room(room, lem);
		if (!room)
			print_error_solution();
	}
	write_room_to_path(room->name, &lem->pathes[lem->pathes_i]);
	lem->pathes_lengthes[0]++;
	lem->shortest_way_length = lem->pathes_lengthes[0];
	lem->pathes_amount++;
	return (lem->pathes[lem->pathes_i]);
}
