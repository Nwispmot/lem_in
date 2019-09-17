/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connections_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:38:11 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:40:08 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				find_dash_index(char *line)
{
	int dash_index;

	dash_index = 0;
	while (line[dash_index])
	{
		if (line[dash_index] == '-')
			return (dash_index);
		dash_index++;
	}
	return (-1);
}

int				check_does_room_exist(char *name, t_lem *lem)
{
	t_room			*ptr;
	int				hash_index;

	hash_index = calculate_hash_index(name);
	ptr = &lem->room_array[hash_index];
	while (ptr)
	{
		if (!ptr->name)
			return (0);
		if (ft_strcmp(name, ptr->name) == 0)
			return (1);
		if (ptr->next_hash)
			ptr = ptr->next_hash;
		else
			break ;
	}
	return (0);
}

int				count_connections_size(char **connections)
{
	int i;

	i = 0;
	while (connections[i])
	{
		i++;
	}
	return (i);
}

void			check_connection_buffer(t_room *room)
{
	char	**temp;
	int		i;
	int		connections_i;
	int		connections_size;

	connections_i = room->connection_i;
	i = 0;
	if (room->connection_i % (CONNECTION_SIZE) == 0 && room->connection_i != 0)
	{
		connections_size = count_connections_size(room->connections);
		temp = ft_memalloc(sizeof(char*) *
		((CONNECTION_SIZE + connections_size) + 1));
		while (i < connections_size)
		{
			temp[i] = ft_strdup(room->connections[i]);
			i++;
		}
		free_connections(room);
		room->connections = temp;
		room->connection_i = connections_i;
	}
}

void			write_connections_to_copy_rooms(t_room *first_room,
char *second_room)
{
	first_room->has_connections = 1;
	if (first_room->connections == NULL)
		first_room->connections = ft_memalloc((sizeof(char*) *
		(CONNECTION_SIZE + 1)));
	check_connection_buffer(first_room);
	first_room->connections[first_room->connection_i] = ft_strdup(second_room);
	first_room->connection_i++;
}
