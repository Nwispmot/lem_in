/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:24:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/07/22 23:42:56 by waddam           ###   ########.fr       */
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

int		ft_valid_str(char *map)
{
	int		i;
	int		fl;
	t_valid	val;

	i = 0;
	fl = 0;

	val.name = 0;
	val.count_x = 0;
	val.count_y = 0;
	val.defice = 0;
	val.space = 0;
	if (map[0] == 'L')
		return (0);
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '-')
		{
			map[i] == ' ' ? val.space++ : val.defice++;
			fl = 0;
			i++;
		}
		else if ((map[i] != ' ' && fl == 0 && val.name < 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != '-' && fl == 0 && val.name < 2 && val.defice == 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 1) /* для валидации координаты x */
		{
			while(map[i] != ' ')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
					return (0);
			}
			val.count_x++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 2)
		{
			while(map[i] != '\0')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else
					return (0);
			}
			val.count_y++;
		}
		else if (val.name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && val.defice == 1) /* валидируем name2 */
		{
			if (map[i] == '#' || map[i] == 'L')
				return (0);
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 1) /* находимся в name */
			i++;
		else
		    return (0);
	}
	if (val.space == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
		return (4);
	else if (val.defice == 1 && val.name == 2)
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
	else if (map[0] == '#' && map[1] != '\0')
	{
		//if (map[1] != '#')
			return (3);
	}
	return (0);
}

int		ft_valid_ants(char **map, t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0] == '#')
		i++;
	if (map[i][0] >= '1' && map[i][0] <= '9')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_isdigit(map[i][j]) == 1)
				j++;
			else
			{
				ft_printf("not valid ants\n"); /* ПРОВЕРКА УБРАТЬ */
				ft_leave();
			}
		}
		lem->ants = ft_atoi(map[i]);
		i++;
		return (i);
	}
	else
	{
		ft_leave();
		return (0);
	}
}

int		ft_validation(char **map, t_lem *lem)
{
	int i;
	int	valid_resh;

	i = ft_valid_ants(map, lem);
	while (map[i])
	{
		if (map[i][0] == '#')
		{
			valid_resh = ft_valid_resh(map[i], lem);
			if (((valid_resh == 1 || valid_resh == 2) && (map[i + 1] != NULL)
			&& (ft_valid_str(map[i + 1]) == 4)) || valid_resh == 3) /* проверяем что после start или end идет строка с координатами комнаты (4) */
				i++;
			else
			{
				ft_printf("2\n");
				ft_leave();
			}
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			lem->count_rooms++;
			i++;
		}
		else if (ft_valid_str(map[i]) == 5)
			i++;
		else
		{
			ft_printf("3\n");
			ft_leave();
		}
	}
	if (lem->start == 1 && lem->end == 1)
		return (1);
	else
		return (0);
}

void	ft_free_room(t_room ***room, int i)
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
			ft_free_room(&room, i);
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

char	**ft_allocate_matrix_char(int dim)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	matrix = (char **)malloc(sizeof(char *) * (dim + 1));
	while (i < dim)
	{
		matrix[i] = ft_strnew(dim);
		ft_memset(matrix[i], '0', dim);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int		**ft_allocate_matrix_int(int dim)
{
	int		i;
	int		**matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * dim);
	while (i < dim)
	{
		matrix[i] = (int *)malloc(sizeof(int) * dim * dim);
		ft_memset(matrix[i], -1, dim * dim * 4);
		i++;
	}
	return (matrix);
}

void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k)
{
	int j;

	j = 0;
	while (matrix[j])
	{
		if (matrix[j] == '1')
		{
			(*tmp)[k + 1][lem->n] = j;
			lem->n++;
		}
		j++;
	}
}

void	ft_find(int ***tmp, int i, int j, int k)
{
	int		l;
	int		m;
	int		num;

	l = 0;
	num = (*tmp)[i][j];
	while (l < k + 1)
	{
		m = 0;
		while ((*tmp)[l][m] >= 0)
		{
			if (((*tmp)[l][m] == num) && !(i == l && j == m))
			{
				while ((*tmp)[l][m] >= 0)
				{
					(*tmp)[l][m] = (*tmp)[l][m + 1];
					m++;
				}
				m = 0;
			}
			m++;
		}
		l++;
	}
}

int		ft_del_repeat(int ***tmp, int k) /* возвращает длину последней строки */
{
	int		i;
	int		j;

	i = 0;
	while (i < k + 1)
	{
		j = 0;
		while ((*tmp)[i][j] >= 0)
		{
			ft_find(tmp, i, j, k);
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while ((*tmp)[i][j] >= 0)
		j++;
	return (j); /* если не зашли в while => строка пустая (все удалили), в противном случае человеческая длина (+1) */
}

void	queue_add(t_queue *qu, t_room *room, int lvl)
{
	t_queue *new;

	new = (t_queue*)malloc(sizeof(t_queue));
	new->name = room;
	new->next = NULL;
	new->name->lvl = lvl;
	new->name->visited = 1;
	while (qu->next != NULL)
		qu = qu->next;
	qu->next = new;
	new->prev = qu;
}
//void add_children(t_queue *children, t_room *room)
//{
//	t_queue *new;
//
//	if (!children)
//	{
//	    //children =
//		children = (t_queue*)malloc(sizeof(t_queue));
//		children->next = NULL;
//		children->name = room;
//		children->prev = NULL;
//	}
//	else
//	{
//        new = (t_queue*)malloc(sizeof(t_queue));
//        while (children->next != NULL)
//            children = children->next;
//        new->name = room;
//        new->next = NULL;
//        new->prev = children;
//        children->next = new;
//	}
//}

t_queue *add_children(t_queue *children, t_room *room)
{
    t_queue *new;
    t_queue *head;

    if (!children)
    {
        //children =
        children = (t_queue*)malloc(sizeof(t_queue));
        head = children;
        children->next = NULL;
        children->name = room;
        children->prev = NULL;
    }
    else
    {
        new = (t_queue*)malloc(sizeof(t_queue));
        head = children;
        while (children->next != NULL)
            children = children->next;
        new->name = room;
        new->next = NULL;
        new->prev = children;
        children->next = new;
    }
    return (head);
}

void add_parent(t_room *parent, t_room *room)
{
    t_queue *new;
   // t_queue *head;

    if (!parent->children)
    {
        parent->children = (t_queue*)malloc(sizeof(t_queue));
       // head = parent;
        parent->children->next = NULL;
        parent->children->name = room;
        parent->children->prev = NULL;
    }
    else
    {
        new = (t_queue*)malloc(sizeof(t_queue));
        //head = parent;
        while (parent->children->next != NULL)
            parent->children = parent->children->next;
        new->name = room;
        new->next = NULL;
        new->prev = parent->children;
        parent->children->next = new;
    }
    //return (head);
}

void	ft_children_parents(t_queue *qu)
{
	t_queue	*head;
	int 	i;

	//i = 0;
	//t_queue *temp;
	head = qu;
	while (qu != NULL)
	{
		i = 0;
		while (qu->name->links[i] != NULL)
		{
			if (qu->name->links[i]->lvl >= qu->name->lvl)
			{
			    qu->name->children = add_children(qu->name->children, qu->name->links[i]);
			   // qu->name->links[i]->parents =
			   add_parent(qu->name->links[i], qu->name);
			}
			i++;
		}
		qu = qu->next;
	}
}

void	bfs(t_room **room)
{
	t_queue *qu;
	int i;
	int lvl;
    t_queue *head;

	lvl = 1;
	qu = (t_queue*)malloc(sizeof(t_queue));
	ft_bzero(qu, sizeof(t_queue));
	head = qu;
    qu->name = room[0];
	qu->next = NULL;
	qu->name->lvl = 1;
    qu->name->visited = 1;
    lvl++;
	while (qu != NULL)
	{

		i = 0;
		while (qu->name->links[i] != NULL)
		{
			if (qu->name->links[i]->visited == 0)
			{
				queue_add(qu, qu->name->links[i], lvl);
			}
			i++;
		}
		qu = qu->next;
		if (qu != NULL && (qu->prev->name->lvl != qu->name->lvl))
		    lvl++;
	}
	qu = head;
	ft_children_parents(qu);
	i = 0;
    while (room[i])
    {
        ft_printf("room = %s | ", room[i]->name);
        while(room[i]->children != NULL)
        {
            ft_printf("c = %s ", head->name->children->name);
            head->name->children = head->name->children->next;
        }
        ft_printf("\n");
        i++;
    }
	while (qu != NULL)
    {
	    ft_printf("r =%s ", qu->name->name);
	    ft_printf("l =%d ", qu->name->lvl);
		ft_printf("\n");
	    qu = qu->next;
    }
	ft_printf("\n");
    i = 0;

//    while (room[i] != NULL) {
//        ft_printf("main_room: %s\n", room[i]->name);
//        while (room[i]->children != NULL)
//        {
//            ft_printf("name: %s\n", room[i]->children->name->name);
//            room[i]->children = room[i]->children->next;
//        }
//        ft_printf("\n");
//        if (ft_strcmp(room[i]->name, room[lem->count_rooms - 1]->name) == 0)
//            break;
//        i++;
//    }


//	exit(0);
}

void	ft_add_node_path(t_room *room, t_path **path)
{
	t_path *new;
	new = (t_path*)malloc(sizeof(t_path));
	new->room = room;
	if (room && path)
	{
		new->next = *path;
		*path = new;
	}
}

void	ft_find_path(t_room **room, t_lem *lem)
{
	int 	i;
	t_room	*temp;
	t_path	*path;

	i = 0;
	temp = room[lem->count_rooms - 1];
	path = (t_path*)malloc(sizeof(t_path));
	path->room = temp;
	path->next = NULL;
	while (ft_strcmp(temp->name, room[0]->name) != 0)
	{
		i = 0;
		while (temp->links[i]->lvl != temp->lvl - 1) // уровень end должен быть на 1 больше следующего минимального (построение пути)
			i++;
		ft_add_node_path(temp->links[i], &path);
		temp = temp->links[i];
	}
	lem->quick_path = path;

	//return (rooms[lem->count_rooms - 1]->links[i]->lvl);

}

t_room 	**ft_record(char **map, t_lem *lem) /* записываем name и координаты (без связей) */
{
	int			i;
	int			k;
	int			valid_resh;
	t_room		**room;

	i = 0; /* 0 строка - это кол-во муравьев - ИСПРАВИТЬ! - там может быть коммент */
	k = 1; /* индекс для массива структур room */
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		valid_resh = ft_valid_resh(map[i], lem);
		// if (map[i][0] == '#' && valid_resh == 3)
		// 	/*i++*/;
		if (map[i][0] == '#' && valid_resh == 1)
		{
			i++;
		    ft_write(map[i], room, 0); /* записать старт на 0 место */
		}
		else if ((map[i][0] == '#' && valid_resh == 2))
		{
			i++;
			ft_write(map[i], room, lem->count_rooms - 1); /*записать end на *room[lem->count_rooms - 1] */
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			ft_write(map[i], room, k);
            k++;
		}
		i++;
	}
	return (room);
}

char	**ft_read_map()
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
	    if (buff[0] == '\n')
	        break;
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		fl = 1;
	}
	if (fl == 0)
		exit(0); /* если пустая карта */
	map = ft_strsplit(temp, '\n');
	return (map);
}

int		ft_search_name(char **map, t_room **room, char end)
{
	int		len_name;
	int		index;
	char	*name;
	char	*temp;

	len_name = 0;
	index = 0;
	temp = *map;
	name = NULL;
	while (**map != end)
	{
		(*map)++;
		len_name++;
	}
	name = ft_strnew(len_name);
	ft_strncpy(name, temp, len_name);
	while (room[index])
	{
		if (ft_strcmp(name, room[index]->name) == 0)
			break ;
		index++;
	}
	return (index);
}

/*
** Количество уже имеющихся в массиве соседних с текущим звеном графа звеньев.
*/

int		ft_count_nodes(t_room **room)
{
	int		len;

	len = 0;
	while (*room != NULL)
	{
		room++;
		len++;
	}
	return (len);
}

void	ft_insert_links(t_room **all_rooms, t_room *room, int neighbour)
{
	t_room	**temp;
	int		len_lst; // длинна уже записанного списка ссылок на элементы (для реалока)
	int		i;

	i = 0;
	if (room->links == NULL)
	{
		room->links = (t_room**)malloc(sizeof(t_room*) * 2);
        bzero(room->links, sizeof(t_room**));
		room->links[1] = NULL;
        room->links[0] = all_rooms[neighbour];
        room->links[0]->empty_fl = 1;
	}
	else
	{
		while (room->links[i] != NULL && room->links[i]->empty_fl == 1)
			i++;
		if (room->links[i] == NULL)
		{
			len_lst = ft_count_nodes(room->links);
			temp = room->links;
			room->links = (t_room**)malloc(sizeof(t_room*) * (len_lst + 2));
			bzero(room->links, sizeof(t_room**));
			ft_memcpy(room->links, temp, sizeof(t_room*) * len_lst);
			room->links[len_lst + 1] = NULL;
			free(temp);
		}
		room->links[i] = all_rooms[neighbour];
		room->links[i]->empty_fl = 1;
	}
}

/* Записываем линки между комнатами на соответствующие позиции матрицы смежности*/
void	ft_write_links(char *map, t_room **room)
{
	int		name1_ind;
	int		name2_ind;

	name1_ind = ft_search_name(&map, room, '-');
	map++;
	name2_ind = ft_search_name(&map, room, '\0');
	ft_printf("d1 == %d d2 == %d\n", name1_ind, name2_ind);
	ft_insert_links(room, room[name1_ind], name2_ind);
	ft_insert_links(room, room[name2_ind], name1_ind);
}

/* Функция создает матрицу смежности */
void	ft_make_links(char **map, t_room **room, t_lem *lem)
{
	int		i;
	int     j;

	i = 0;
	while (map[i])
	{
		if (ft_valid_str(map[i]) == 5)
			ft_write_links(map[i], room);
		i++;
	}
	i = 0;
	while (room[i] != NULL) {
        j = 0;
        ft_printf("main_room: %s\n", room[i]->name);
        while (room[i]->links[j] != NULL) {
            ft_printf("name: %s\n", room[i]->links[j]->name);
            j++;
        }
        ft_printf("\n");
        if (ft_strcmp(room[i]->name, room[lem->count_rooms - 1]->name) == 0)
            break;
        i++;
    }
}

int			main(void)
{
	t_lem	lem; /* списки смежности */
	char	**map; 			/* карта */
	t_room	**room; 		/* массив структур для комнат */

	ft_initialization_lem(&lem);
	map = ft_read_map();
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit (0);
    check_repeat_name(&lem, room);
    check_repeat_coordinates(&lem, room);
	ft_make_links(map, room, &lem);
	bfs(room);
	ft_find_path(room, &lem);
	while (lem.quick_path->next != NULL)
	{
		ft_printf("%s->", lem.quick_path->room->name);
		lem.quick_path = lem.quick_path->next;
	}
    ft_printf("%s", lem.quick_path->room->name);
	ft_printf("\n");
	ft_printf("OK\n");
    exit(0);
}
