/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:57:02 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 13:18:41 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_exit(t_data *data)
{
	if (data->count_collect == data->nbcollect)
		return (0);
	return (1);
}

void	put_backgr(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->height - 64;
	while (x <= data->weight)
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.i_bk, x, y);
		x += 64;
	}
}

// mlx_set_font(data->mlx_ptr, data->win_ptr, FONT);
void	header(t_data *data)
{
	put_backgr(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->weight
		- (data->weight * 90 / 100), data->height - 25, 0xFFFFFF, "Dino");
	data->str = "nb coups: ";
	data->strcount = ft_itoa(data->count);
	if (!data->strcount)
		end(data, 1);
	data->print = ft_strjoin(data->str, data->strcount);
	if (!data->print)
		end(data, 1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->weight
		- (data->weight * 20 / 100), data->height - 25, 0xFFFFFF, data->print);
	free (data->strcount);
	free (data->print);
	data->str = "nb collect: ";
	data->strcount = ft_itoa(data->count_collect);
	if (!data->strcount)
		end(data, 1);
	data->print = ft_strjoin(data->str, data->strcount);
	if (!data->print)
		end(data, 1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->weight
		- (data->weight * 55 / 100), data->height - 25, 0xFFFFFF, data->print);
	free (data->strcount);
	free (data->print);
}

static void	init_variable(t_data *data, size_t *len, char **argv)
{
	data->timer = 1;
	data->count = 0;
	data->count_collect = 0;
	data->boolean = 0;
	data->boolean2 = 2;
	data->boolean_ennemi = 0;
	data->boolean_ennemi2 = 1;
	data->boolean_sword = 0;
	data->boolean_collect = 0;
	data->ind.x = 1000;
	data->ind.y = 666;
	*len = ft_strlenn(argv[1]);
	data->map_path = argv[1];
}

int	main(int argc, char **argv)
{
	t_data	data;
	size_t	len;

	if (argc == 2)
	{
		init_variable(&data, &len, argv);
		if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
			|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.'
			|| argv[1][len - 5] > 127 || argv[1][len - 5] < 31)
		{
			ft_printf(BER);
			return (1);
		}
		launch_first_window(&data);
		launch_game(&data);
	}
	else
	{
		ft_printf(E);
		return (1);
	}
	return (0);
}
