/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:31:38 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:32:20 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			delete_connection(char *name_to_find, t_room *room)
{
	int		i;

	i = 0;
	while (i < room->connection_i)
	{
		if (ft_strcmp(name_to_find, room->connections[i]) == 0)
		{
			ft_strdel(&room->connections[i]);
			room->connections[i] = ft_strdup("L");
			break ;
		}
		i++;
	}
}

void			copy_connections(char ***dest, char **orig, int connection_i)
{
	int		i;

	i = 0;
	*dest = ft_memalloc(sizeof(char*) * connection_i);
	while (i < connection_i)
	{
		(*dest)[i] = ft_strdup(orig[i]);
		i++;
	}
}

void			copy_hash(t_room *orig, t_lem *lem)
{
	t_room	*temp;

	while (orig->next_hash)
	{
		orig = orig->next_hash;
		temp = create_room_copy(orig->name, lem);
		copy_connections(&temp->connections, orig->connections,
		orig->connection_i);
	}
}

void			copy_room_array(t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		ptr = &lem->room_array[i];
		if (ptr->name)
		{
			create_room_copy(ptr->name, lem);
			copy_connections(&lem->room_array_copy[i].connections,
			ptr->connections, ptr->connection_i);
			if (ptr->next_hash)
				copy_hash(ptr, lem);
		}
		i++;
	}
}

void			replace_connection_from_room(t_room *room,
char *name_to_replace, char *replace_name)
{
	int		i;

	i = 0;
	while (i < room->connection_i)
	{
		if (ft_strcmp(room->connections[i], name_to_replace) == 0)
		{
			ft_strdel(&room->connections[i]);
			room->connections[i] = ft_strdup(replace_name);
			break ;
		}
		i++;
	}
}
