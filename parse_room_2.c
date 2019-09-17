/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:20:08 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:16:27 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				count_output_length(long long int d)
{
	int length;

	if (d == 0)
		return (1);
	length = 0;
	if (d < 0)
	{
		d = -d;
		length++;
	}
	while (d > 0)
	{
		d = d / 10;
		length++;
	}
	return (length);
}

int				count_till_space(char *line)
{
	int		i;

	i = 0;
	while (line)
	{
		if (line[i] == ' ')
			return (i);
		i++;
	}
	return (-1);
}

t_room			*create_room_copy_simple(char *line, t_lem *lem)
{
	t_room	*temp;
	int		hash_index;
	t_room	*fuck_u;

	temp = ft_memalloc(sizeof(t_room));
	hash_index = calculate_hash_index(line);
	temp->name = ft_strdup(line);
	temp->is_end = 0;
	temp->is_start = 0;
	temp->is_visited = 0;
	temp->counter = lem->room_array[hash_index].counter;
	temp->connection_i = lem->room_array[hash_index].connection_i;
	temp->has_connections = lem->room_array[hash_index].has_connections;
	temp->lvl = 0;
	temp->next_hash = NULL;
	fuck_u = write_room_to_array_copy(lem, hash_index, temp);
	free(temp);
	return (fuck_u);
}

t_room			*create_room_copy(char *line, t_lem *lem)
{
	t_room	*temp;
	int		hash_index;
	t_room	*fuck_u;
	t_room	*room;

	room = find_room_by_name(line, &lem);
	temp = ft_memalloc(sizeof(t_room));
	hash_index = calculate_hash_index(line);
	temp->name = ft_strdup(line);
	temp->is_end = 0;
	temp->is_start = 0;
	temp->is_visited = 0;
	temp->counter = room->counter;
	temp->connection_i = room->connection_i;
	temp->has_connections = room->has_connections;
	temp->lvl = 0;
	temp->next_hash = NULL;
	fuck_u = write_room_to_array_copy(lem, hash_index, temp);
	free(temp);
	return (fuck_u);
}

void			create_room_2(t_lem *lem, int hash_index,
char *line, t_room *temp)
{
	temp->is_visited = 0;
	temp->connections = NULL;
	temp->counter = 0;
	temp->has_connections = 0;
	temp->connection_i = 0;
	temp->next_hash = NULL;
	write_room_to_array(lem, hash_index, temp);
	write_line_to_info("\n", lem);
	write_line_to_info(line, lem);
	(*lem).room_quantity++;
}
