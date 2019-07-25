#include "lemin.h"

void    check_repeat_name(t_lem	*lem, t_room **room) //добавить
{
    int i;
    int j;

    i = 0;
    while (i < lem->count_rooms)
    {
        j = 0;
        while (j < lem->count_rooms)
        {
            if (i == j || (ft_strcmp(room[i]->name, room[j]->name) != 0))
                j++;
            else
            {
                ft_printf("repName\n");
                exit(0);
            }
        }
        i++;
    }
}

void    check_repeat_coordinates(t_lem	*lem, t_room **room) //добавить
{
    int i;
    int j;

    i = 0;
    while (i < lem->count_rooms)
    {
        j = 0;
        while (j < lem->count_rooms)
        {
            if (i == j || (room[i]->x != room[j]->x || room[i]->y != room[j]->y))
                j++;
            else
            {
                ft_printf("repCoor\n");
                exit(0);
            }
        }
        i++;
    }
}