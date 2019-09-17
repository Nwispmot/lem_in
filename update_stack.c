/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:01:26 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:58:40 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			move_stack(char **stack, int i)
{
	while (stack[i + 1])
	{
		ft_strcpy(stack[i], stack[i + 1]);
		i++;
	}
}

void			exclude_room_from_stack(char *name, char **stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (ft_strcmp(stack[i], name) == 0)
		{
			move_stack(stack, i);
			i = 0;
			continue ;
		}
		i++;
	}
}

void			free_path_aray(char **path_array)
{
	int		i;

	i = 0;
	while (path_array[i])
	{
		ft_strdel(&(path_array[i]));
		i++;
	}
	ft_strdel(&(path_array[i]));
	free(path_array);
}

void			update_stack(char *path, char **stack, t_lem *lem)
{
	char	**path_array;
	int		i;

	i = 0;
	path_array = ft_strsplit(path, ' ');
	while (path_array[i])
	{
		if (ft_strcmp(path_array[i], lem->end) != 0 &&
		ft_strcmp(path_array[i], lem->start) != 0)
			exclude_room_from_stack(path_array[i], stack);
		i++;
	}
	free_path_aray(path_array);
}
