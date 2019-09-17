/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:19:33 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 19:20:15 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			find_pathes_2(t_lem *lem, t_room **start, int *flag)
{
	double_rooms(lem);
	clear_room_stack(lem);
	add_room_name_to_stack((*start)->name, lem);
	(*start) = find_room_copy_by_name(lem->start, &lem);
	(*start)->is_visited = 1;
	(*start)->lvl = 1;
	bfs_copy(lem);
	if (!(collect_shortest_way_copy(lem)))
		*flag = 0;
	initialize_is_visited(lem);
}

void			find_pathes_3(t_lem *lem, t_room **start, int *flag)
{
	lem->pathes_amount = 0;
	lem->is_cross_found = 0;
	clear_room_array_copy(lem);
	delete_cross(lem);
	copy_room_array(lem);
	clear_room_stack(lem);
	add_room_name_to_stack((*start)->name, lem);
	*flag = 1;
	(*start)->is_visited = 1;
	(*start)->lvl = 1;
	free_pathes(lem);
	lem->pathes_i--;
	bfs_copy(lem);
	if (!(collect_shortest_way_copy(lem)))
		*flag = 0;
	initialize_is_visited(lem);
}

void			find_pathes_4(t_lem *lem, t_room **start, int *flag)
{
	double_rooms(lem);
	clear_room_stack(lem);
	add_room_name_to_stack((*start)->name, lem);
	(*start) = find_room_copy_by_name(lem->start, &lem);
	(*start)->is_visited = 1;
	(*start)->lvl = 1;
	bfs_copy(lem);
	if (!(collect_shortest_way_copy(lem)))
		*flag = 0;
	initialize_is_visited(lem);
}

void			find_pathes_6(t_lem *lem, int *flag, t_room **start)
{
	*flag = 1;
	lem->pathes_lengthes = ft_memalloc(sizeof(int) * lem->room_quantity);
	lem->pathes_lengthes_ptr = lem->pathes_lengthes;
	initialize_pathes_lengthes(lem);
	lem->room_stack = ft_memalloc(sizeof(char*) * (*lem).room_quantity * 2);
	(*start) = find_room_by_name(lem->start, &lem);
	(*start)->is_visited = 1;
	(*start)->lvl = 1;
	add_room_name_to_stack((*start)->name, lem);
	bfs(lem);
	lem->shortest_way = ft_strdup(collect_shortest_way(lem));
	copy_room_array(lem);
}

void			find_pathes(t_lem *lem)
{
	t_room	*start;
	int		flag;

	find_pathes_6(lem, &flag, &start);
	while (flag)
		find_pathes_2(lem, &start, &flag);
	restore_pathes(lem);
	update_counters(lem);
	while (lem->is_cross_found)
	{
		if (find_crossing_pathes(lem))
		{
			find_pathes_3(lem, &start, &flag);
			while (flag)
				find_pathes_4(lem, &start, &flag);
			restore_pathes(lem);
			update_counters(lem);
		}
		else
			return ;
	}
	reverse_pathes(lem);
	sort_pathes(lem);
	ants_logistics(lem);
}
