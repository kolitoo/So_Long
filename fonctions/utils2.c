/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:21:58 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 12:33:57 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	del_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.im_w);
	mlx_destroy_image(data->mlx_ptr, data->img.im_f);
	mlx_destroy_image(data->mlx_ptr, data->img.im_c);
	mlx_destroy_image(data->mlx_ptr, data->img.im_e);
	mlx_destroy_image(data->mlx_ptr, data->img.i_en);
	mlx_destroy_image(data->mlx_ptr, data->img.img_p);
	mlx_destroy_image(data->mlx_ptr, data->img.i_p2);
	mlx_destroy_image(data->mlx_ptr, data->img.i_s);
	mlx_destroy_image(data->mlx_ptr, data->img.i_bk);
}

void	free_map(t_data *data, char **map)
{
	data->ind.i = 0;
	while (map[data->ind.i] != NULL)
	{
		free(map[data->ind.i]);
		data->ind.i++;
	}
	free(map);
}

int	end(t_data *data, int l)
{
	if (l == 1)
	{
		del_img(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_lstclear(&data->start);
	free_all_map(data);
	exit(EXIT_SUCCESS);
}

int	global_check2(t_data *data)
{
	int	dep;

	dep = -1;
	find_letter (data, 'P', &data->ind.backi, &data->ind.backj);
	if (check_map_rectangle(data) == 0)
	{
		ft_printf(PAS_FERMEE);
		end(data, 0);
	}
	if (check_form_map(data) == 0)
	{
		ft_printf(PAS_RECTANGLE);
		end(data, 0);
	}
	if (backtrack(data->map_back, data->ind.backj, data->ind.backi, dep) == 0)
	{
		ft_printf(ERROR_SORTIE);
		end(data, 0);
	}
	if (backtrack_col(data->mapcol, data->ind.backj, data->ind.backi, dep) == 0)
	{
		ft_printf(ERROR_C);
		end(data, 0);
	}
	return (1);
}

void	img_2_win(t_data *data, char *img)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, data->ind.x, data->ind.y);
}
