/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:36:36 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 20:07:01 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			check_pathes_buffer(t_lem *lem, int count)
{
	char	**temp;
	int		i;

	i = 0;
	if (count % PATHES_SIZE == 0 && count != 0)
	{
		temp = ft_memalloc(sizeof(char*) * ((count + 2) + 1));
		while (i < count)
		{
			temp[i] = ft_strdup(lem->pathes[i]);
			i++;
		}
		free_pathes_index(lem, count);
		lem->pathes = temp;
	}
}

int				check_is_all_visited(t_lem *lem)
{
	int			i;

	i = 0;
	while (lem->room_stack[i])
	{
		if (ft_strcmp(lem->end, lem->room_stack[i]) == 0 ||
		ft_strcmp(lem->start, lem->room_stack[i]) == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int				count_stack_size(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->room_stack[i])
		i++;
	return (--i);
}

void			parse_stack_for_pathes_2(t_lem *lem, int *i)
{
	char	*shortest_way;
	char	*start;
	char	*end;

	start = lem->start;
	end = lem->end;
	check_pathes_buffer(lem, *i);
	lem->is_way_found = 0;
	shortest_way = find_shortest_way(end, lem);
	printf("%s\n", shortest_way);
	if (lem->is_way_found == 1)
	{
		lem->pathes[*i] = shortest_way;
		i++;
		lem->pathes_amount++;
		lem->pathes_lengthes_ptr++;
		update_stack(shortest_way, lem->room_stack, lem);
	}
	else
	{
		(*lem->pathes_lengthes_ptr) = 0;
		update_stack(shortest_way, lem->room_stack, lem);
		ft_strdel(&shortest_way);
	}
}

void			parse_stack_for_pathes(t_lem *lem)
{
	int		i;
	int		stack_size;

	stack_size = count_stack_size(lem);
	i = 0;
	if (!lem->pathes)
		lem->pathes = ft_memalloc(sizeof(char*) * (PATHES_SIZE + 1));
	while (!check_is_all_visited(lem) && !lem->stop_parsing_stack)
	{
		parse_stack_for_pathes_2(lem, &i);
	}
}
