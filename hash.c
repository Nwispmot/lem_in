/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:33:44 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:30:12 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_room			*write_room_to_array_copy(t_lem *lem,
int hash_index, t_room *room)
{
	t_room	*temp;

	temp = &lem->room_array_copy[hash_index];
	if (!temp->name)
	{
		*temp = *room;
		return (temp);
	}
	else
	{
		while (temp->next_hash)
		{
			temp = temp->next_hash;
			if (!temp->name)
			{
				*temp = *room;
				return (temp);
			}
		}
		temp->next_hash = ft_memalloc(sizeof(t_room));
		*temp->next_hash = *room;
		temp->next_hash->next_hash = NULL;
		return (temp->next_hash);
	}
}

void			write_room_to_array(t_lem *lem, int hash_index, t_room *room)
{
	t_room	*temp;

	temp = &lem->room_array[hash_index];
	if (!temp->name)
		*temp = *room;
	else
	{
		while (temp->next_hash)
		{
			temp = temp->next_hash;
			if (!temp->name)
			{
				*temp = *room;
				return ;
			}
		}
		temp->next_hash = ft_memalloc(sizeof(t_room));
		*temp->next_hash = *room;
		temp->next_hash->next_hash = NULL;
	}
}

int				calculate_hash_index(char *line)
{
	int		sum;
	int		index;

	sum = 0;
	while (*line != ' ' && *line)
	{
		sum += *line;
		line++;
	}
	index = sum % ARRAY_SIZE;
	return (index);
}
