/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:24:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/27 19:38:07 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_leave(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	ft_initialization_lem(t_lem *lem)
{
	ft_bzero(lem, sizeof(t_lem));
}

void	ft_initialization_room(t_room *room)
{
	ft_bzero(room, sizeof(t_room));
}

int		ft_valid_str(char *map, t_lem *lem)
{
	int i;
	int fl;
	int tmp;

	i = 0;
	fl = 0;
	tmp = lem->count_rooms;
	ft_initialization_lem(lem);
	lem->count_rooms = tmp;
	if (map[0] == 'L')
		return (0);
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '-')
		{
			map[i] == ' ' ? lem->space++ : lem->defice++;
			fl = 0;
			i++;
		}
		else if ((map[i] != ' ' && fl == 0 && lem->name < 1))
		{
			lem->name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != '-' && fl == 0 && lem->name < 2 && lem->defice == 1))
		{
			lem->name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && lem->space == 1)
		{
			while(map[i] != ' ')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
					return (0);
			}
			lem->count_x++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && lem->space == 2)
		{
			while(map[i] != '\0')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else
					return (0);
			}
			lem->count_y++;
		}
		else if (lem->name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && lem->defice == 1)
		{
			if (map[i] == '#' || map[i] == 'L')
				return (0); 
			lem->name++;
			fl = 1;
			i++;	
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 1)
			i++;
		else
		    return (0);
	}	
	if (lem->space == 2 && lem->name == 1 && lem->count_x == 1 && lem->count_y == 1)
		return (4);
	else if (lem->defice == 1 && lem->name == 2)
		return (5);
	else
		return (0);
}

int		ft_valid_resh(char *map, t_lem *lem) /* проверяем start, end и comment*/
{
	int i;

	i = 0;
	if (ft_strcmp(map, "##start") == 0)
	{
		lem->start++;
		return (1);
	}
	else if (ft_strcmp(map, "##end") == 0)
	{
		lem->end++;
		return (2);
	}
	else if (map[0] == '#' && map[1] != '\0') /* придумать более строгую проверку на коммент */
	{
		if (map[1] != '#')
			return (3);
	}
	return (0);
}

int		ft_validation(char **map, t_lem *lem)
{
	int i;
	
	i = 0;
	while (map[0][i])
	{
		if (ft_isdigit(map[0][i]) == 1)
			i++;
		else
			ft_leave();
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] == '#')
		{
			if (((ft_valid_resh(map[i], lem) == 1 || ft_valid_resh(map[i], lem) == 2) && (map[i + 1] != NULL) 
			&& (ft_valid_str(map[i + 1], lem) == 4)) || ft_valid_resh(map[i], lem) == 3) /* проверяем что после start или end идет строка с координатами комнаты (4) */
				i++;
			else
				ft_leave();
		}
		else if (ft_valid_str(map[i], lem) == 4)
		{
			lem->count_rooms++;
			i++;
		}
		else if (ft_valid_str(map[i], lem) == 5)
			i++;
		else
			ft_leave();
	}
//	if (lem->start == 1 && lem->end == 1)   Убрал это условие
//		return (1);
//	else
		return (1);
}

void	ft_free(t_room ***room, int i)
{
	while (--i >= 0)
	{
		free((*room)[i]);
		(*room)[i] = NULL;
	}
	free(*room);
	*room = NULL;
}

t_room	**ft_allocate_memory(t_lem *lem)
{
	int		i;
	t_room	**room;

	i = 0;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * (lem->count_rooms + 1))))
		ft_leave();
	while (i < lem->count_rooms)
	{
		if (!(room[i] = (t_room *)malloc(sizeof(t_room))))
		{
			ft_free(&room, i);
			return (NULL);
		}
		ft_initialization_room(room[i]);
		i++;
	}
    return (room);
}

void 	ft_write(char *map, t_room **room, int k) /* Записывает Name x y */
{
    int co;

    co = 0;
    while (map[co] != ' ')
        co++;
    room[k]->name = ft_strnew(co);
    ft_strncpy(room[k]->name, map, co);
    room[k]->x = ft_atoi(&map[co]);
    co++;
    while (map[co] != ' ')
        co++;
    room[k]->y = ft_atoi(&map[co]);
}

void 	ft_record(char **map, t_lem *lem)
{
	int i;
	int k;
	t_room **room;

	i = 1; /* 0 строка - это кол-во муравьев*/
	k = 1;
	lem->ants = ft_atoi(map[0]);
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		if (map[i][0] == '#' && ft_valid_resh(map[i], lem) == 3)
			i++;
		else if (map[i][0] == '#' && ft_valid_resh(map[i], lem) == 1)
        {
		    i++;
		    ft_write(map[i], room, 0);
			/* записать старт на 0 место */
		}
		else if ((map[i][0] == '#' && ft_valid_resh(map[i], lem) == 2))
		{
		    i++;
            ft_write(map[i], room, lem->count_rooms - 1);
			/*записать на *room[lem->count_rooms - 1] */
		}
		else if (ft_valid_str(map[i], lem) == 4)
		{
            ft_write(map[i], room, k);
            k++;
		}
//		else if (ft_valid_resh(map[i], lem) == 5)
//		{
//          Сделать линки
//		}
		i++;
	}
	i = 0;
	while (i < lem->count_rooms)
	{
		ft_printf("name == %s\n", room[i]->name);
		ft_printf("x == %d y == %d", room[i]->x, room[i]->y);
		ft_printf("\n\n");
		i++;
	}
}

void	ft_read_map(t_lem *lem)
{
	int		ret;
    char	buff[BUFF_SIZE + 1];
	char	*del;
	char	*temp;
	int 	fl;
	char	**map;

	fl = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		fl = 1;
	}
	if (fl == 0)
		exit(0); /* если пустая карта */
	map = ft_strsplit(temp, '\n');
	if (ft_validation(map, lem) == 1)
		ft_record(map, lem);
	else
		ft_leave();
}

int		main(void)
{
    t_lem	*lem;

	lem = (t_lem *)malloc(sizeof(t_lem));
	ft_initialization_lem(lem);
	ft_read_map(lem);
	ft_printf("valid\n");
	exit(0);
}