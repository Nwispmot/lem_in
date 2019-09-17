/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:17:06 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:18:48 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				is_parent(t_room *parent_room, char *child_name)
{
	int		i;

	i = parent_room->connection_i;
	while (i > 0)
	{
		if (ft_strcmp(parent_room->connections[i - 1], child_name) == 0)
			return (1);
		i--;
	}
	return (0);
}
