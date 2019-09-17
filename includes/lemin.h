/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:03:05 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:20:17 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <limits.h>
# include "../libft/libft.h"
# include <fcntl.h>
# define CONNECTION_SIZE 2
# define PATHES_SIZE 2
# define ARRAY_SIZE 5000

typedef struct		s_room
{
	char			*name;
	int				is_double;
	int				is_start;
	int				is_end;
	char			**connections;
	int				has_connections;
	int				is_visited;
	int				connection_i;
	int				counter;
	struct s_room	*next_hash;
	int				lvl;
}					t_room;

typedef	struct		s_ants
{
	char			*name;
	struct s_ants	*next;
	char			**path;
	char			**path_head;
	int				started;
}					t_ants;

typedef struct		s_lem
{
	int				i;
	int				starts;
	int				ends;
	int				shortest_way_length;
	int				cross_path_i;
	int				is_cross_found;
	char			*cross_rooms;
	char			*out_room;
	char			*start;
	char			*end;
	int				fd;
	int				ants_amount;
	char			*map_info;
	int				is_start;
	int				is_end;
	int				room_quantity;
	char			**pathes;
	t_room			*room_head;
	char			**room_stack;
	char			*shortest_way;
	int				is_way_found;
	int				all_is_visited;
	int				**ants_logistics;
	int				pathes_amount;
	int				*logistics_time;
	int				*pathes_lengthes_ptr;
	int				*pathes_lengthes;
	int				best_logistics_index;
	t_ants			*ants_head;
	int				ant_i;
	int				stop_parsing_stack;
	int				pathes_i;
	t_room			room_array[ARRAY_SIZE];
	t_room			room_array_copy[ARRAY_SIZE];
}					t_lem;

void				validate_map(t_lem *lem);
void				print_error_ants();
void				parse_room(char *line, t_lem *lem);
void				print_error_room();
void				check_ants_amount(t_lem *lem);
void				write_line_to_info(char *line, t_lem *lem);
void				free_lem(t_lem *lem);
void				write_connections_to_rooms(char *first_room,
char *second_room, t_lem *lem);
void				print_error_comment();
void				find_pathes(t_lem *lem);
void				bfs(t_lem *lem);
t_room				*find_room_by_name(char *name, t_lem **lem);
void				add_room_name_to_stack(char *line, t_lem *lem);
t_room				*find_end_room(t_lem *lem);
t_room				*find_start_room(t_lem *lem);
void				free_list_room(t_lem *lem);
void				free_connections(t_room *ptr);
void				create_room(char *line, t_lem *lem);
void				check_connections(t_lem *lem, char *line);
void				free_room_stack(t_lem *lem);
t_room				*find_end_room(t_lem *lem);
t_room				*find_next_room_in_stack(t_lem *lem);
int					find_empty_array_index(char **stack_array);
void				parse_stack_for_pathes(t_lem *lem);
void				write_room_to_path(char *name, char **path);
void				update_stack(char	*path, char	**stack, t_lem *lem);
void				free_pathes(t_lem *lem);
void				ants_logistics(t_lem *lem);
void				free_logistics(t_lem *lem);
void				print_lem(t_lem *lem);
void				free_ants(t_lem *lem);
void				walk_step(t_lem **lem);
void				print_step(char *name, char *room);
char				*start_one_ant(t_lem *lem);
char				*start_second_ant(char	**room_list, t_lem *lem);
void				free_pathes_index(t_lem *lem, int count);
int					calculate_hash_index(char *line);
void				write_room_to_array(t_lem *lem, int hash_index,
t_room	*room);
void				check_pathes_buffer(t_lem *lem, int count);
t_room				*create_room_copy(char *line, t_lem *lem);
t_room				*write_room_to_array_copy(t_lem *lem,
int hash_index, t_room *room);
t_room				*find_room_copy_by_name(char *name, t_lem **lem);
void				write_connections_to_copy_rooms(t_room *first_room,
char *second_room);
void				bfs_copy(t_lem *lem);
int					is_parent(t_room	*parent_room, char	*child_name);
void				reverse_pathes(t_lem *lem);
void				reverse_path(int index, t_lem *lem);
t_room				*create_room_copy_simple(char *line, t_lem *lem);
int					check_does_room_exist(char *name, t_lem *lem);
void				print_error_solution();
int					count_till_space(char *line);
int					count_output_length(long long int d);
void				create_room_2(t_lem *lem, int hash_index,
char *line, t_room *temp);
void				create_room(char *line, t_lem *lem);
int					is_everybody_home(t_lem *lem);
int					find_crossing_pathes(t_lem *lem);
void				update_counters(t_lem *lem);
int					update_counter(char *path, t_lem *lem);
void				restore_pathes(t_lem *lem);
char				*restore_path(char *path, t_lem *lem);
void				sort_pathes(t_lem *lem);
void				initialize_is_visited(t_lem *lem);
void				add_room_name_to_line(char *name, char **line);
t_room				*find_room_by_name(char *name, t_lem **lem);
t_room				*find_room_copy_by_name(char *name, t_lem **lem);
char				*collect_shortest_way(t_lem *lem);
int					collect_shortest_way_copy(t_lem *lem);
t_room				*get_lower_lvl_room(t_room *room, t_lem *lem);
int					get_lower_lvl_copy_room(t_lem *lem);
void				initialize_pathes_lengthes(t_lem *lem);
void				replace_connection_from_room(t_room *room,
char *name_to_replace, char *replace_name);
void				copy_room_array(t_lem *lem);
void				copy_hash(t_room *orig, t_lem *lem);
void				copy_connections(char ***dest, char **orig,
int connection_i);
void				delete_connection(char *name_to_find, t_room *room);
void				clear_room_array_copy(t_lem *lem);
void				clear_room_stack(t_lem *lem);
void				double_rooms(t_lem *lem);
t_room				*create_in_out(char **path, int i, t_lem *lem);
void				write_connections_to_connections(t_room *room,
t_room *in_room,
t_room *out_room, t_lem *lem);
void				write_ants_to_logistics(int ants_per_path,
int i, t_lem *lem);
void				free_connections(t_room *ptr);
void				parse_stack_for_pathes(t_lem *lem);
int					count_stack_size(t_lem *lem);
int					check_is_all_visited(t_lem *lem);
void				check_pathes_buffer(t_lem *lem, int count);
char				*find_shortest_way(char *end, t_lem *lem);
int					is_parent(t_room *parent_room, char *child_name);
void				check_connection_buffer(t_room *room);
int					count_connections_size(char **connections);
int					check_does_room_exist(char *name, t_lem *lem);
int					find_dash_index(char *line);
void				clear_room_array_copy_2(t_room *tmp);
void				clear_room_array_copy(t_lem *lem);
void				clear_room_array_copy(t_lem *lem);
void				clear_room_stack(t_lem *lem);
void				find_pathes_6(t_lem *lem, int *flag, t_room **start);
void				find_pathes_4(t_lem *lem, t_room **start, int *flag);
void				find_pathes_3(t_lem *lem, t_room **start, int *flag);
void				find_pathes_2(t_lem *lem, t_room **start, int *flag);
void				delete_cross(t_lem *lem);
void				restore_path_2(t_lem *lem, char **split,
char **ret, int *i);
void				initialize_pathes_lengthes(t_lem *lem);
char				*collect_shortest_way(t_lem *lem);
int					collect_shortest_way_copy(t_lem *lem);
char				*find_shortest_way(char *end, t_lem *lem);
int					is_parent(t_room *parent_room, char *child_name);
void				write_remainder_to_logistics(int ants_remainder,
int i, t_lem *lem);
int					count_cur_time(int *ants_logistics, t_lem *lem);
void				free_str_point(char **str);
#endif
