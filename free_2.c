/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:40:35 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:44:12 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			free_connections(t_room *ptr)
{
	while (ptr->connection_i != 0)
	{
		ft_strdel(&(ptr->connections[ptr->connection_i - 1]));
		ptr->connection_i--;
	}
	free(ptr->connections);
}

void			free_ant_path(char **path)
{
	int i;

	i = 0;
	while (path[i])
	{
		ft_strdel(&path[i]);
		i++;
	}
	free(path);
}

void			free_ants(t_lem *lem)
{
	int		i;
	t_ants	*ptr;

	ptr = lem->ants_head;
	i = 0;
	while (lem->ants_head)
	{
		ptr = lem->ants_head;
		ft_strdel(&(lem->ants_head->name));
		free_ant_path(ptr->path_head);
		lem->ants_head = ptr->next;
		free(ptr);
	}
}

void			full_free_ants_logistics(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->pathes_amount)
	{
		free(lem->ants_logistics[i]);
		i++;
	}
	free(lem->ants_logistics);
}

void			free_logistics(t_lem *lem)
{
	free(lem->logistics_time);
	free(lem->pathes_lengthes);
	full_free_ants_logistics(lem);
}
