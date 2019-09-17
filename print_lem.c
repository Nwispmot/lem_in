/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:01:31 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:43:27 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			add_ant_to_list(char *path, t_lem *lem)
{
	t_ants		*temp;
	char		**path_arr;

	path_arr = ft_strsplit(path, ' ');
	temp = (t_ants *)ft_memalloc(sizeof(t_ants));
	temp->path = path_arr;
	temp->path_head = temp->path;
	temp->started = 0;
	temp->next = lem->ants_head;
	lem->ants_head = temp;
}

void			create_ants_list(t_lem *lem)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = lem->ants_amount;
	while (lem->ants_logistics[lem->best_logistics_index][j] != 0)
	{
		while (i > 0 && k < lem->ants_logistics[lem->best_logistics_index][j])
		{
			add_ant_to_list(lem->pathes[j], lem);
			i--;
			k++;
		}
		k = 0;
		j++;
	}
}

void			add_room_to_array(char *room, char **room_list, t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->room_quantity)
	{
		if (!room_list[i])
		{
			room_list[i] = ft_strdup(room);
			return ;
		}
		i++;
	}
}

void			start_ants(t_lem *lem)
{
	int		i;
	char	*room;
	char	**room_list;

	room_list = ft_memalloc(sizeof(char*) * lem->room_quantity);
	i = lem->pathes_amount;
	room = start_one_ant(lem);
	if (room)
		add_room_to_array(room, room_list, lem);
	while (--i)
	{
		room = start_second_ant(room_list, lem);
		if (!room)
			break ;
		add_room_to_array(room, room_list, lem);
	}
	free_str_point(room_list);
}

void			print_lem(t_lem *lem)
{
	create_ants_list(lem);
	while (!is_everybody_home(lem))
	{
		start_ants(lem);
		walk_step(&lem);
		write(1, "\n", 1);
	}
}
