/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:33 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/19 16:09:03 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	win_len(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y][x] != '\0')
		x++;
	while (data->map[y] != NULL)
		y++;
	data->weight = x * 64;
	data->height = (y * 64) + 64;
}

static void	set_image2(t_data *data, int *x, int *y)
{
	if (data->boolean2 == 1)
	{
		data->img.p = "./textures/caracterswordL.xpm";
		data->img.p2 = "./textures/caractersword2L.xpm";
	}
	else if (data->boolean2 == 2)
	{
		data->img.p = "./textures/caractersword.xpm";
		data->img.p2 = "./textures/caractersword2.xpm";
	}
	data->img.img_p = mlx_xpm_file_to_image(data->mlx_ptr, data->img.p, x, y);
	data->img.i_p2 = mlx_xpm_file_to_image(data->mlx_ptr, data->img.p2, x, y);
	data->img.w = "./textures/Mur.xpm";
	data->img.im_w = mlx_xpm_file_to_image(data->mlx_ptr, data->img.w, x, y);
	data->img.f = "./textures/floor.xpm";
	data->img.im_f = mlx_xpm_file_to_image(data->mlx_ptr, data->img.f, x, y);
}

void	set_image(t_data *data)
{
	int	x;
	int	y;

	x = data->weight;
	y = data->height;
	set_image2(data, &x, &y);
	if (data->boolean_collect == 0)
		data->img.c = "./textures/collect.xpm";
	else if (data->boolean_collect == 1)
		data->img.c = "./textures/collect1.xpm";
	data->img.im_c = mlx_xpm_file_to_image(data->mlx_ptr, data->img.c, &x, &y);
	data->img.s = "./textures/sword.xpm";
	data->img.i_s = mlx_xpm_file_to_image(data->mlx_ptr, data->img.s, &x, &y);
	if (check_exit(data) == 1)
		data->img.e = "./textures/exit.xpm";
	data->img.im_e = mlx_xpm_file_to_image(data->mlx_ptr, data->img.e, &x, &y);
	data->img.en = "./textures/ennemi.xpm";
	data->img.i_en = mlx_xpm_file_to_image(data->mlx_ptr, data->img.en, &x, &y);
	data->img.bk = "./textures/background.xpm";
	data->img.i_bk = mlx_xpm_file_to_image(data->mlx_ptr, data->img.bk, &x, &y);
}

static void	choose_texture2(t_data *data)
{
	if (data->map[data->ind.j][data->ind.i] == 'C')
		img_2_win(data, data->img.im_c);
	else if (data->map[data->ind.j][data->ind.i] == 'P')
	{
		if (data->count % 2 == 0)
			img_2_win(data, data->img.img_p);
		else
			img_2_win(data, data->img.i_p2);
	}
	else if (data->map[data->ind.j][data->ind.i] == 'E')
		img_2_win(data, data->img.im_e);
	else if (data->map[data->ind.j][data->ind.i] == '3')
		img_2_win(data, data->img.i_en);
}

void	choose_texture(t_data *data)
{
	data->ind.x = 0;
	data->ind.y = 0;
	data->ind.i = 0;
	data->ind.j = 0;
	while (data->map[data->ind.j] != NULL)
	{
		while (data->map[data->ind.j][data->ind.i] != '\0')
		{
			if (data->map[data->ind.j][data->ind.i] == '0')
				img_2_win(data, data->img.im_f);
			else if (data->map[data->ind.j][data->ind.i] == '1')
				img_2_win(data, data->img.im_w);
			choose_texture2(data);
			data->ind.x = data->ind.x + 64;
			data->ind.i++;
		}
		data->ind.i = 0;
		data->ind.x = 0;
		data->ind.y = data->ind.y + 64;
		data->ind.j++;
	}
	header(data);
}
