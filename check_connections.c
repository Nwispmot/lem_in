/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:11:39 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:38:02 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			write_connections_to_rooms(char *first_room,
char *second_room, t_lem *lem)
{
	t_room		*ptr;

	ptr = find_room_by_name(first_room, &lem);
	ptr->has_connections = 1;
	if (ptr->connections == NULL)
		ptr->connections = ft_memalloc((sizeof(char*) * (CONNECTION_SIZE + 1)));
	check_connection_buffer(ptr);
	ptr->connections[ptr->connection_i] = ft_strdup(second_room);
	ptr->connection_i++;
}

void			write_connections_to_info(char *first_room,
char *second_room, t_lem *lem)
{
	write_line_to_info("\n", lem);
	write_line_to_info(first_room, lem);
	write_line_to_info("-", lem);
	write_line_to_info(second_room, lem);
}

int				count_second_room_len(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void			check_connections_2(char *line, char *second_room,
char *first_room, t_lem *lem)
{
	if (check_does_room_exist(second_room, lem))
	{
		write_connections_to_rooms(first_room, second_room, lem);
		write_connections_to_rooms(second_room, first_room, lem);
		write_connections_to_info(first_room, second_room, lem);
	}
	else
		print_error_room();
	if (line[ft_strlen(first_room) + ft_strlen(second_room) + 1] != '\0')
		print_error_room();
	ft_strdel(&first_room);
	ft_strdel(&second_room);
}

void			check_connections(t_lem *lem, char *line)
{
	int		dash_index;
	char	*first_room;
	char	*second_room;

	dash_index = find_dash_index(line);
	first_room = ft_memalloc(dash_index + 1);
	ft_strncpy(first_room, line, dash_index);
	if (check_does_room_exist(first_room, lem))
	{
		second_room = ft_memalloc(count_second_room_len(line +
		dash_index + 1) + 1);
		ft_strcpy(second_room, line + dash_index + 1);
		check_connections_2(line, second_room, first_room, lem);
	}
	else
		print_error_room();
}
