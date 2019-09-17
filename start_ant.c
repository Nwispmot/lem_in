/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:38:23 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:58:01 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char			*start_one_ant(t_lem *lem)
{
	t_ants *ptr;

	ptr = lem->ants_head;
	while (ptr)
	{
		if (!ptr->started)
		{
			ptr->started = 1;
			ptr->name = ft_itoa(lem->ant_i);
			lem->ant_i++;
			return (*(ptr->path + 1));
		}
		ptr = ptr->next;
	}
	return (NULL);
}

int				check_room_list(char **room_list, char *room)
{
	while (*room_list)
	{
		if (ft_strcmp(*room_list, room) == 0)
			return (1);
		room_list++;
	}
	return (0);
}

char			*start_second_ant(char **room_list, t_lem *lem)
{
	t_ants *ptr;

	ptr = lem->ants_head;
	while (ptr)
	{
		if (!ptr->started)
		{
			if (!check_room_list(room_list, *(ptr->path + 1)))
			{
				ptr->started = 1;
				ptr->name = ft_itoa(lem->ant_i);
				lem->ant_i++;
				return (*(ptr->path + 1));
			}
		}
		ptr = ptr->next;
	}
	return (NULL);
}
