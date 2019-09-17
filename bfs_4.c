/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:07:08 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:00:58 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			f1(char **path, t_lem *lem, int i)
{
	ft_strdel(path);
	write_room_to_path(lem->room_stack[i], path);
}

void			f2(char *end, char **path, t_lem *lem)
{
	write_room_to_path(end, path);
	(*lem->pathes_lengthes_ptr)++;
	lem->is_way_found = 1;
}

char			*f3(char **path, t_lem *lem, int i)
{
	if (ft_strcmp(lem->room_stack[i], lem->start) == 0)
		lem->stop_parsing_stack = 1;
	ft_strdel(path);
	write_room_to_path(lem->room_stack[i], path);
	return (*path);
}

int				f4(t_lem *lem, char *end, int i, char *path)
{
	if (ft_strcmp(lem->room_stack[i + 1], end) == 0)
	{
		f2(end, &path, lem);
		return (1);
	}
	write_room_to_path(lem->room_stack[i + 1], &path);
	return (0);
}

char			*find_shortest_way(char *end, t_lem *lem)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = -1;
	write_room_to_path(lem->start, &path);
	while (lem->room_stack[++j + 1])
	{
		if (!(find_room_by_name(lem->room_stack[i], &lem)->has_connections))
		{
			f1(&path, lem, i);
			return (path);
		}
		if (is_parent(find_room_by_name(lem->room_stack[i], &lem),
		lem->room_stack[j + 1]))
		{
			i = j;
			if (f4(lem, end, i, path))
				return (path);
			(*lem->pathes_lengthes_ptr)++;
			i++;
		}
	}
	return (f3(&path, lem, i));
}
