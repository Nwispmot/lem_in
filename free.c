/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:29:52 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:35:39 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			free_pathes(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->pathes[i])
	{
		ft_strdel(&(lem->pathes[i]));
		lem->pathes_lengthes[i] = 0;
		i++;
	}
	lem->pathes_i = 0;
}

void			free_pathes_index(t_lem *lem, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_strdel(&(lem->pathes[i]));
		i++;
	}
	free(lem->pathes);
}

void			free_rooms_array_2(t_room *ptr)
{
	t_room	*ptr2;

	ptr2 = ptr->next_hash;
	if (ptr->has_connections)
		free_connections(ptr);
	ft_strdel(&(ptr->name));
	free(ptr);
	ptr = ptr2;
}

void			free_rooms_array(t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		ptr = &lem->room_array[i];
		while (ptr)
		{
			if (ptr->next_hash)
				free_rooms_array_2(ptr);
			else
			{
				if (ptr->has_connections)
					free_connections(ptr);
				ft_strdel(&(ptr->name));
				free(ptr);
				break ;
			}
		}
	}
}

void			free_lem(t_lem *lem)
{
	ft_strdel(&(*lem).map_info);
	free_pathes(lem);
	free_rooms_array(lem);
}
