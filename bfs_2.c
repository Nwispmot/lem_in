/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:28:50 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:16:54 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			write_path_to_pathes(char *path, t_lem *lem)
{
	lem->pathes[find_empty_array_index(lem->pathes)] = ft_strdup(path);
}

void			bfs_copy_2(t_room **room, int *i, t_room **ptr, t_lem *lem)
{
	if (!(find_room_copy_by_name((*room)->connections[*i - 1],
	&lem)->is_visited))
	{
		add_room_name_to_stack((*room)->connections[*i - 1], lem);
		*ptr = find_room_copy_by_name((*room)->connections[*i - 1],
		&lem);
		(*ptr)->is_visited = 1;
		(*ptr)->lvl = (*room)->lvl + 1;
	}
}

void			bfs_copy(t_lem *lem)
{
	int		i;
	t_room	*room;
	t_room	*ptr;
	char	**temp;

	temp = lem->room_stack;
	while (*temp)
	{
		room = find_room_copy_by_name(*temp, &lem);
		if (room->has_connections)
		{
			i = room->connection_i;
			while (i != 0)
			{
				if (room->connections[i - 1][0] == 'L')
				{
					i--;
					continue ;
				}
				bfs_copy_2(&room, &i, &ptr, lem);
				i--;
			}
		}
		temp++;
	}
}

void			bfs_2(t_room **room, t_lem *lem, t_room **ptr, int i)
{
	if (!(find_room_by_name((*room)->connections[i - 1],
	&lem)->is_visited))
	{
		add_room_name_to_stack((*room)->connections[i - 1], lem);
		*ptr = find_room_by_name((*room)->connections[i - 1], &lem);
		(*ptr)->is_visited = 1;
		(*ptr)->lvl = (*room)->lvl + 1;
	}
}

void			bfs(t_lem *lem)
{
	int		i;
	t_room	*room;
	t_room	*ptr;
	char	**temp;

	temp = lem->room_stack;
	while (*temp)
	{
		room = find_room_by_name(*temp, &lem);
		if (room->has_connections)
		{
			i = room->connection_i;
			while (i != 0)
			{
				bfs_2(&room, lem, &ptr, i);
				i--;
			}
		}
		temp++;
	}
}
