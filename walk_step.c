/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:54:08 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:59:42 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			print_step(char *name, char *room)
{
	write(1, "L", 1);
	ft_putstr(name);
	write(1, "-", 1);
	ft_putstr(room);
	write(1, " ", 1);
}

void			walk_step(t_lem **lem)
{
	t_ants		*ptr;

	ptr = (*lem)->ants_head;
	while (ptr)
	{
		if (ptr->started && *(ptr->path + 1))
		{
			print_step(ptr->name, *(ptr->path + 1));
			ptr->path++;
		}
		ptr = ptr->next;
	}
}
