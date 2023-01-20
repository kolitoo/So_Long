/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:14 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 10:16:56 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handle_input2(int keysym, t_data *data)
{
	if (move_player(data, keysym) == 1)
	{
		if (data->boolean != 1)
		{
			del_img(data);
			set_image(data);
		}
		choose_texture(data);
	}
	else if (move_player(data, keysym) == 0)
	{
		data->count++;
		ft_printf(WIN, data->count, data->count_collect);
		end(data, 1);
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data, 1);
	if (keysym == S || keysym == A || keysym == W || keysym == D
		||keysym == UP || keysym == DO || keysym == RI || keysym == LE)
		handle_input2(keysym, data);
	return (0);
}

int	keycheck_start(int keysym, t_data *data)
{
	if (keysym == XK_KP_Enter || keysym == XK_Return)
		mlx_loop_end(data->mlx_ptr2);
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr2, data->img.img_win1);
		mlx_loop_end(data->mlx_ptr2);
		mlx_destroy_window(data->mlx_ptr2, data->win_ptr2);
		mlx_destroy_display(data->mlx_ptr2);
		free (data->mlx_ptr2);
		end (data, 0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	end(data, 1);
	return (0);
}

int	close_window_2(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr2, data->img.img_win1);
	mlx_loop_end(data->mlx_ptr2);
	mlx_destroy_window(data->mlx_ptr2, data->win_ptr2);
	mlx_destroy_display(data->mlx_ptr2);
	free (data->mlx_ptr2);
	end (data, 0);
	return (0);
}
