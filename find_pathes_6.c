/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:32:53 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:35:52 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			write_connections_to_connections(t_room *room, t_room *in_room,
t_room *out_room, t_lem *lem)
{
	int		i;

	i = 0;
	while (i < room->connection_i)
	{
		if (room->connections[i])
		{
			if (room->connections[i][0] == 'L')
			{
				i++;
				continue ;
			}
			replace_connection_from_room(find_room_copy_by_name(
			room->connections[i], &lem), room->name, in_room->name);
			write_connections_to_copy_rooms(out_room, room->connections[i]);
			i++;
		}
	}
}

t_room			*create_in_out(char **path, int i, t_lem *lem)
{
	char	*name;
	t_room	*out_room;
	t_room	*in_room;

	name = ft_strjoin(path[i], "in");
	in_room = create_room_copy_simple(name, lem);
	in_room->is_double = 1;
	ft_strdel(&name);
	name = ft_strjoin(path[i], "out");
	out_room = create_room_copy_simple(name, lem);
	out_room->is_double = 1;
	ft_strdel(&name);
	write_connections_to_copy_rooms(out_room, in_room->name);
	write_connections_to_connections(find_room_copy_by_name(
		path[i], &lem), in_room, out_room, lem);
	lem->out_room = out_room->name;
	return (in_room);
}

void			double_rooms_2(t_lem *lem, t_room *in_room,
char **path, char *next_out)
{
	int		i;

	i = lem->i;
	if (i == lem->pathes_lengthes[0] - 2)
	{
		in_room = create_in_out(path, i, lem);
		next_out = ft_strjoin(path[i - 1], "in");
		write_connections_to_copy_rooms(
		find_room_copy_by_name(next_out, &lem), lem->out_room);
		write_connections_to_copy_rooms(in_room, path[i + 1]);
		ft_strdel(&next_out);
	}
	else
	{
		ft_strdel(&next_out);
		next_out = ft_strjoin(path[i - 1], "in");
		write_connections_to_copy_rooms(
		find_room_copy_by_name(next_out, &lem), path[i]);
		ft_strdel(&next_out);
	}
}

void			double_rooms_3(t_lem *lem, char **path)
{
	int			i;

	i = 1;
	while (i < lem->pathes_lengthes[lem->pathes_i])
	{
		delete_connection(path[i - 1], find_room_copy_by_name(path[i], &lem));
		delete_connection(path[i], find_room_copy_by_name(path[i - 1], &lem));
		i++;
	}
}

void			double_rooms(t_lem *lem)
{
	char	**path;
	t_room	*in_room;
	char	*next_out;
	t_room	*prev_in;

	lem->i = 1;
	path = ft_strsplit(lem->pathes[lem->pathes_i], ' ');
	double_rooms_3(lem, path);
	prev_in = find_room_copy_by_name(path[lem->i - 1], &lem);
	while (lem->i < lem->pathes_lengthes[lem->pathes_i] - 2)
	{
		in_room = create_in_out(path, lem->i, lem);
		if (lem->i > 1)
			write_connections_to_copy_rooms(prev_in,
			create_in_out(path, lem->i + 1, lem)->name);
		else
			create_in_out(path, lem->i + 1, lem);
		next_out = ft_strjoin(path[lem->i + 1], "out");
		write_connections_to_copy_rooms(in_room, next_out);
		ft_strdel(&next_out);
		prev_in = in_room;
		lem->i += 2;
	}
	double_rooms_2(lem, in_room, path, next_out);
	free_str_point(path);
}
