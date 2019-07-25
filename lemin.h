#ifndef LEMIN_H
#define LEMIN_H
# define BUFF_SIZE 1024
# include "libft/libft.h"

typedef struct      s_room
{
    char            *name;
    int             x;
    int             y;
    int             fl;
    int             lvl;
    int             empty_fl;
    int             visited;
    //struct s_room   **parents;
    struct s_queue  *parents;
    struct s_queue  *children;
    struct s_room   **links; // массив, содержащий сслыки на связные элементы
}
t_room;
typedef struct      s_path
{
    struct s_room   *room;
    struct s_path   *next;
}                   t_path;

typedef struct      s_lem
{
    int             i;
    int             n;
    int             ants;
    int             count_rooms;
    int             start;
    int             end;
    int             len;
    t_path      	*quick_path;
}                   t_lem;



typedef struct      s_valid
{
    int             name;
    int             space;
    int             defice;
    int             count_x;
    int             count_y;
}                   t_valid;

typedef	struct		s_queue
{

    struct s_room   *name;
    struct s_queue	*prev;
    struct s_queue	*next;

}					t_queue;

//typedef struct      s_path
//{
//    int             i;
//    int             j;
//    int             res;
//    int             **path;
//    int             count_paths;
//    //struct  s_path  *next;
//}                   t_path;

typedef struct      s_res
{
    int             i;
    int             j;
    int             res;
    int             **path;
    int             count_paths;
    //struct  s_path  *next;
}                   t_res;

char	**ft_read_map();
int		ft_validation(char **map, t_lem *lem);
int		ft_valid_str(char *map);
int		ft_valid_resh(char *map, t_lem *lem);
void	ft_initialization_lem(t_lem *lem);
void	ft_leave(void);
void	ft_free(t_room ***room, int i);
void 	ft_write(char *map, t_room **room, int k);
t_room	**ft_record(char **map, t_lem *lem);
void    check_repeat_coordinates(t_lem	*lem, t_room **room);
void    check_repeat_name(t_lem	*lem, t_room **room);
//void	ft_write_lvl_in_room(t_room **room, int **tmp);


# endif
