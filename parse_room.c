/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:40:03 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:16:01 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			create_room_3(t_room *temp, t_lem *lem)
{
	if (check_does_room_exist(temp->name, lem) == 1)
		print_error_room();
	if ((*lem).is_start)
	{
		temp->is_start = 1;
		lem->start = ft_strdup(temp->name);
	}
	if ((*lem).is_end)
	{
		temp->is_end = 1;
		lem->end = ft_strdup(temp->name);
	}
}

void			create_room(char *line, t_lem *lem)
{
	t_room	*temp;
	int		space_index;
	int		hash_index;

	temp = ft_memalloc(sizeof(t_room));
	if ((space_index = count_till_space(line)))
	{
		hash_index = calculate_hash_index(line);
		temp->name = ft_strnew(space_index);
		ft_strncpy(temp->name, line, space_index);
		create_room_3(temp, lem);
		create_room_2(lem, hash_index, line, temp);
	}
	else
	{
		free_lem(lem);
		print_error_room();
	}
	free(temp);
}

void			check_line_is_room(char *line, t_lem *lem)
{
	int		count_space;

	count_space = 0;
	while (*line)
	{
		if (*line == ' ')
		{
			line++;
			if (count_space > 2)
			{
				print_error_room();
				free_lem(lem);
			}
			count_space++;
			continue ;
		}
		line++;
	}
}

void			get_room_name(char *line, t_lem *lem)
{
	check_line_is_room(line, lem);
	create_room(line, lem);
}

void			parse_room(char *line, t_lem *lem)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	if (split[3] != NULL || split[2] == NULL || split[1] == NULL)
		print_error_room();
	if (line[0] == 'L' || line[0] == '#')
	{
		print_error_room();
		free_lem(lem);
	}
	get_room_name(line, lem);
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}
