/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:28:01 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:28:54 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_room			*find_room_copy_by_name(char *name, t_lem **lem)
{
	t_room		*ptr;
	int			hash_index;

	hash_index = calculate_hash_index(name);
	ptr = &(*lem)->room_array_copy[hash_index];
	while (ptr)
	{
		if (ft_strcmp(ptr->name, name) == 0)
			return (ptr);
		if (ptr->next_hash)
			ptr = ptr->next_hash;
		else
			break ;
	}
	return (0);
}

t_room			*find_room_by_name(char *name, t_lem **lem)
{
	t_room		*ptr;
	int			hash_index;

	hash_index = calculate_hash_index(name);
	ptr = &(*lem)->room_array[hash_index];
	while (ptr)
	{
		if (ft_strcmp(ptr->name, name) == 0)
			return (ptr);
		if (ptr->next_hash)
			ptr = ptr->next_hash;
		else
			break ;
	}
	return (0);
}

void			add_room_name_to_line(char *name, char **line)
{
	char	*temp;

	temp = ft_strjoin(*line, "-");
	ft_strdel(line);
	*line = ft_strdup(temp);
	temp = ft_strjoin(*line, name);
	ft_strdel(line);
	*line = ft_strdup(temp);
}

void			initialize_is_visited(t_lem *lem)
{
	int		i;
	t_room	*ptr;

	i = 0;
	while (i < ARRAY_SIZE - 302)
	{
		ptr = &lem->room_array_copy[i];
		while (ptr)
		{
			ptr->is_visited = 0;
			if (ptr->next_hash)
				ptr = ptr->next_hash;
			else
				break ;
		}
		i++;
	}
}

void			sort_pathes(t_lem *lem)
{
	int		i;
	char	*temp;
	int		length_temp;

	i = 0;
	while (i < lem->pathes_amount - 1)
	{
		if (lem->pathes_lengthes[i] > lem->pathes_lengthes[i + 1])
		{
			length_temp = lem->pathes_lengthes[i];
			lem->pathes_lengthes[i] = lem->pathes_lengthes[i + 1];
			lem->pathes_lengthes[i + 1] = length_temp;
			temp = ft_strdup(lem->pathes[i]);
			ft_strdel(&(lem->pathes[i]));
			lem->pathes[i] = lem->pathes[i + 1];
			lem->pathes[i + 1] = temp;
			sort_pathes(lem);
		}
		i++;
	}
}
