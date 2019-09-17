/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:19:50 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:32:21 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				find_empty_array_index(char **stack_array)
{
	int		i;

	i = 0;
	while (stack_array[i] != '\0')
		i++;
	return (i);
}

void			add_room_name_to_stack(char *line, t_lem *lem)
{
	int		empty_array_index;

	if (!(*(lem->room_stack)))
		*lem->room_stack = ft_strdup(line);
	else
	{
		empty_array_index = find_empty_array_index(lem->room_stack);
		lem->room_stack[empty_array_index] = ft_strdup(line);
	}
}

t_room			*find_next_room_in_stack(t_lem *lem)
{
	int		i;
	t_room	*room;

	i = 1;
	while (i < 10000)
	{
		if (lem->room_stack[i - 1])
		{
			room = find_room_by_name(lem->room_stack[i - 1], &lem);
			if (!room->is_visited)
			{
				if (!(room->is_end))
					return (room);
			}
		}
		i++;
	}
	return (NULL);
}

void			write_room_to_path(char *name, char **path)
{
	char		*temp;

	if (!(*path))
		*path = ft_strdup(name);
	else
	{
		temp = ft_strjoin(*path, " ");
		ft_strdel(path);
		*path = ft_strdup(temp);
		ft_strdel(&temp);
		temp = ft_strjoin(*path, name);
		ft_strdel(*(&path));
		*path = temp;
	}
}
