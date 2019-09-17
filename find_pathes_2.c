/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:25:38 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:32:24 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char			*restore_path(char *path, t_lem *lem)
{
	int		i;
	char	**split;
	char	*ret;

	ret = ft_strnew(0);
	i = 0;
	split = ft_strsplit(path, ' ');
	while (split[i])
	{
		restore_path_2(lem, split, &ret, &i);
		i++;
	}
	free_str_point(split);
	return (ret);
}

void			restore_pathes(t_lem *lem)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < lem->pathes_i)
	{
		tmp = restore_path(lem->pathes[i], lem);
		ft_strdel(&lem->pathes[i]);
		lem->pathes[i] = tmp;
		i++;
	}
}

int				update_counter(char *path, t_lem *lem)
{
	int		i;
	char	**split;
	t_room	*room;

	i = 1;
	split = ft_strsplit(path, ' ');
	while (split[i + 1])
	{
		room = find_room_copy_by_name(split[i], &lem);
		room->counter++;
		if (room->counter >= 2)
		{
			lem->cross_rooms = ft_strdup(split[i + 1]);
			lem->cross_rooms = ft_strjoin_free(lem->cross_rooms, " ", 1, 0);
			lem->cross_rooms = ft_strjoin_free(lem->cross_rooms,
			room->name, 1, 0);
			free_str_point(split);
			return (0);
		}
		i++;
	}
	free_str_point(split);
	return (1);
}

void			update_counters(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->pathes_i)
	{
		if (!update_counter(lem->pathes[i], lem))
		{
			lem->is_cross_found = 1;
			lem->cross_path_i = i;
			break ;
		}
		i++;
	}
}

int				find_crossing_pathes(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->cross_path_i)
	{
		if (ft_strstr(lem->pathes[i], lem->cross_rooms))
			return (1);
		i++;
	}
	return (0);
}
