#ifndef LEMIN_H
#define LEMIN_H
//# define BUFF_SIZE 1024

#include "libft/libft.h"

typedef struct      s_room
{
    char            *name;
    int             x;
    int             y;
    int             fl;
    int             lv;
    struct  s_room   *next;
}                   t_room;

typedef struct      s_lem
{
    int             ants;
    int             count_rooms;
    int             start;
    int             end;
    int             name;
    int             space;
    int             defice;
    int             count_x;
    int             count_y;
}                   t_lem;

# endif

void	ft_read_map(t_lem *lem);
int		ft_validation(char **map, t_lem *lem);
int		ft_valid_str(char *map, t_lem *lem);
int		ft_valid_resh(char *map, t_lem *lem);
void	ft_initialization_lem(t_lem *lem);
void	ft_leave(void);
void	ft_free(t_room ***room, int i);

