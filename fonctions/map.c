/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 12:57:34 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_no_event(t_data *data)
{
	if (data->timer % 20000 == 0)
	{
		if (data->boolean != 1)
		{
			if (data->boolean_collect == 0)
				data->boolean_collect = 1;
			else
				data->boolean_collect = 0;
			del_img(data);
			set_image(data);
			choose_texture(data);
		}
	}
	if (data->timer % 10000 == 0)
	{
		if (ennemi_move(data, &data->start) == 0)
			ft_lstclear(&data->start);
		choose_texture(data);
	}
	data->timer++;
	if (data->timer == 20001)
		data->timer = 1;
	return (0);
}

void	set_map2(int fd, char **str, char **temp)
{
	if (*temp == NULL)
	{
		free (*str);
		ft_printf(MAP_VIDE);
		exit(EXIT_SUCCESS);
	}
	while (*temp != NULL)
	{
		if (ft_strlenn(*temp) < 3)
		{
			free (*str);
			free (*temp);
			ft_printf(MAP_PB);
			exit(EXIT_SUCCESS);
		}
		*str = join(*str, *temp);
		*temp = get_next_line(fd);
	}
}

int	set_map(t_data *data)
{
	char	*str;
	char	*temp;
	int		fd;

	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (0);
	str[0] = '\0';
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
	{
		free (str);
		ft_printf(ERROR_PATH);
		return (0);
	}
	temp = get_next_line(fd);
	set_map2(fd, &str, &temp);
	set_map3(data, str);
	free (str);
	free (temp);
	return (1);
}

int	launch_first_window(t_data *data)
{
	if (set_map(data) == 0)
		exit(EXIT_SUCCESS);
	data->start = ft_lstremplir(data);
	win_len(data);
	global_check(data);
	global_check2(data);
	data->mlx_ptr2 = mlx_init();
	if (data->mlx_ptr2 == NULL)
		end(data, 0);
	data->win_ptr2 = mlx_new_window(data->mlx_ptr2, 1000, 666, "Start");
	if (data->win_ptr2 == NULL)
		end(data, 0);
	data->img.win1 = "./textures/bg.xpm";
	data->img.img_win1 = mlx_xpm_file_to_image
		(data->mlx_ptr2, data->img.win1, &data->ind.x, &data->ind.y);
	mlx_put_image_to_window(data->mlx_ptr2,
		data->win_ptr2, data->img.img_win1, 0, 0);
	mlx_key_hook(data->win_ptr2, &keycheck_start, data);
	mlx_hook(data->win_ptr2, 17, 0, close_window_2, data);
	mlx_loop(data->mlx_ptr2);
	return (1);
}

int	launch_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr2, data->img.img_win1);
	mlx_loop_end(data->mlx_ptr2);
	mlx_destroy_window(data->mlx_ptr2, data->win_ptr2);
	mlx_destroy_display(data->mlx_ptr2);
	free(data->mlx_ptr2);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr
		= mlx_new_window(data->mlx_ptr, data->weight, data->height, "Dino");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	count_collect(data->map, &data->nbcollect);
	set_image(data);
	choose_texture(data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
