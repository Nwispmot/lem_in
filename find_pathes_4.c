/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:30:10 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 19:45:34 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			get_lower_lvl_room_2(t_room **ptr, int *cur_lvl,
char **name, t_lem *lem)
{
	if ((*ptr)->lvl == *cur_lvl - 1)
	{
		if (is_parent(*ptr, *name) == 1)
		{
			write_room_to_path((*ptr)->name, &lem->pathes[lem->pathes_i]);
			lem->pathes_lengthes[lem->pathes_i]++;
			*name = (*ptr)->name;
			*cur_lvl = (*ptr)->lvl;
		}
	}
}

void			get_lower_lvl_copy_room_3(int *cur_lvl,
t_room **ptr, char **name, t_lem *lem)
{
	*cur_lvl = (*ptr)->lvl;
	*name = (*ptr)->name;
	write_room_to_path((*ptr)->name, &lem->pathes[lem->pathes_i]);
	lem->pathes_lengthes[lem->pathes_i]++;
}

int				get_lower_lvl_copy_room(t_lem *lem)
{
	char	**temp;
	int		i;
	int		cur_lvl;
	char	*name;
	t_room	*ptr;

	i = 0;
	temp = lem->room_stack;
	while (lem->room_stack[i])
		i++;
	i--;
	while (i >= 0 && ft_strcmp(lem->room_stack[i], lem->end) != 0)
		i--;
	if (i + 1 == 0)
		return (0);
	ptr = find_room_copy_by_name(temp[i], &lem);
	get_lower_lvl_copy_room_3(&cur_lvl, &ptr, &name, lem);
	i--;
	while (i >= 0)
	{
		ptr = find_room_copy_by_name(temp[i], &lem);
		get_lower_lvl_room_2(&ptr, &cur_lvl, &name, lem);
		i--;
	}
	return (1);
}

t_room			*get_lower_lvl_room(t_room *room, t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < room->connection_i)
	{
		ptr = find_room_by_name(room->connections[i], &lem);
		if (ptr->lvl == room->lvl - 1)
			return (ptr);
		i++;
	}
	return (NULL);
}
