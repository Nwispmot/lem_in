/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:02:23 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:54:56 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			zero_room_array_copy(t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		ptr = &lem->room_array_copy[i];
		ft_bzero(ptr, sizeof(t_room*));
		ptr->next_hash = NULL;
		i++;
	}
}

void			zero_room_array(t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		ptr = &lem->room_array[i];
		ft_bzero(ptr, sizeof(t_room*));
		ptr->next_hash = NULL;
		i++;
	}
}

void			initialize_lem(t_lem *lem)
{
	(*lem).room_head = NULL;
	(*lem).ants_head = NULL;
	(*lem).room_quantity = 0;
	lem->ants_amount = 0;
	lem->is_end = 0;
	lem->is_start = 0;
	lem->is_cross_found = 0;
	lem->cross_path_i = -1;
	lem->pathes = NULL;
	lem->map_info = NULL;
	lem->is_way_found = 0;
	lem->all_is_visited = 0;
	lem->pathes_amount = 0;
	lem->ants_logistics = NULL;
	lem->ant_i = 1;
	lem->stop_parsing_stack = 0;
	zero_room_array(lem);
	zero_room_array_copy(lem);
}

void			print_info(t_lem *lem)
{
	ft_putstr(lem->map_info);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

int				main(void)
{
	t_lem		lem;

	lem.fd = 0;
	initialize_lem(&lem);
	validate_map(&lem);
	find_pathes(&lem);
	print_info(&lem);
	print_lem(&lem);
	exit(0);
}
