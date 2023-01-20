/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:22:16 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 12:44:58 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# define FONT "-*-*-*-*-*-*-*-200-*-*-*-*-*-*"
# define WIN "Bravo ! Vous avez gagne en %d coups et collecte %d objets !"
# define ENLOSE "Perdu ! Le dragon rouge vous a touche !"
# define BER "Error\nSaisissez un fichier *.ber"
# define E "Error\nSaisissez 2 arguements : nom du programmes + chemin de la map"
# define PAS_FERMEE "Error\nLa carte n'est pas fermee"
# define PAS_RECTANGLE "Error\nLa carte n'est pas rectangle"
# define ELEM_NON_VALIDE "Error\nLes elements de la carte ne sont pas valides"
# define ERROR_NB_P "Error\nNombre de personnage non valide"
# define ERROR_NB_E "Error\nNombre de sortie non valide"
# define ERROR_NB_C "Error\nNombre de collectibles non valide"
# define ERROR_SORTIE "Error\nLa sortie n'est pas accessible"
# define ERROR_C "Error\nUn ou plusieurs collectibles ne sont pas accessibles"
# define MAP_VIDE "ERROR\nLa map est vide"
# define MAP_PB "ERROR\nLa map a un probleme"
# define ERROR_PATH "Error\nLe path n'est pas valide"
# define S 0x0073
# define A 0x0061
# define W 0x0077
# define D 0x0064
# define UP 0xff52
# define DO 0xff54
# define RI 0xff53
# define LE 0xff51

typedef struct s_img
{
	void	*im_w;
	void	*im_f;
	void	*im_c;
	void	*i_c2;
	void	*img_p;
	void	*im_e;
	void	*i_p2;
	void	*i_en;
	void	*i_el;
	void	*img_win1;
	void	*i_bk;
	void	*i_s;
	char	*e;
	char	*w;
	char	*f;
	char	*c;
	char	*c2;
	char	*p;
	char	*p2;
	char	*en;
	char	*el;
	char	*win1;
	char	*s;
	char	*bk;
}t_img;

typedef struct s_ind
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	backi;
	int	backj;
	int	k;
}t_ind;

typedef struct s_en
{
	int			i;
	int			j;
	int			live;
	int			boolean_direction;
	char		*img;
	char		*img2;
	void		*i_img;
	void		*i_img2;
	struct s_en	*next;
}t_en;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_ptr2;
	void	*win_ptr;
	void	*win_ptr2;
	char	*map_path;
	char	**map;
	char	**map_back;
	char	**mapcol;
	char	*str;
	char	*strcount;
	char	*print;
	int		weight;
	int		height;
	int		count;
	int		count_collect;
	int		nbcollect;
	int		boolean;
	int		boolean2;
	int		boolean_ennemi;
	int		boolean_ennemi2;
	int		boolean_sword;
	int		boolean_collect;
	int		boolean_ennemi_nb;
	int		timer;
	t_img	img;
	t_ind	ind;
	t_en	*start;
}t_data;

int		set_map(t_data *test);
int		move_player(t_data *data, int keysym);
int		global_check(t_data *data);
int		global_check2(t_data *data);
int		check_valid_elem(t_data *data);
int		check_elem_nb(t_data *data, char c);
int		check_map_rectangle(t_data *data);
int		check_form_map(t_data *data);
int		handle_input(int keysym, t_data *data);
int		close_window(t_data *data);
int		close_window_2(t_data *data);
int		handle_no_event(t_data *data);
int		launch_game(t_data *data);
int		keycheck_start(int keysym, t_data *data);
int		launch_first_window(t_data *data);
int		backtrack(char **map_backtrack, int j, int i, int dep);
int		backtrack_col(char **map_backtrack_col, int j, int i, int dep);
int		ennemi_move(t_data *data, t_en **temp);
int		check_exit(t_data *data);
int		find_letter(t_data *data, char c, int *i, int *j);
int		count_collect(char **map, int *nbcollect);
int		end(t_data *data, int l);
void	img_2_win(t_data *data, char *img);
void	win_len(t_data *data);
void	set_image(t_data *data);
void	header(t_data *data);
void	collect_move(t_data *data);
void	player_pos(char **map_backtrack, int *i, int *j, char c);
void	del_img(t_data *data);
void	free_map(t_data *data, char **map);
void	choose_texture(t_data *data);
void	ft_lstadd_back(t_en **start, t_en *temp);
void	ft_lstclear(t_en **lst);
void	free_all_map(t_data *data);
void	set_map3(t_data *data, char *str);
char	*launch_backtrack(char **map_backtrack, char *str, int *i, int *j);
t_en	*ft_lstnew(int i, int j, int live, int boolean);
t_en	*ft_lstremplir(t_data *data);

#endif