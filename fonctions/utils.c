/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:38 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 12:57:23 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_move(t_data *data)
{
	int	x;
	int	y;

	x = data->weight;
	y = data->height;
	mlx_destroy_image(data->mlx_ptr, data->img.img_p);
	mlx_destroy_image(data->mlx_ptr, data->img.i_p2);
	data->img.p = "./textures/caracterC.xpm";
	data->img.img_p = mlx_xpm_file_to_image(data->mlx_ptr, data->img.p, &x, &y);
	data->img.p2 = "./textures/caracterC.xpm";
	data->img.i_p2 = mlx_xpm_file_to_image(data->mlx_ptr, data->img.p2, &x, &y);
	data->count_collect++;
	data->boolean = 1;
	if (check_exit(data) == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.im_e);
		data->img.e = "./textures/exit2.xpm";
		data->img.im_e = mlx_xpm_file_to_image
			(data->mlx_ptr, data->img.e, &x, &y);
	}
}

int	find_letter(t_data *data, char c, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (data->map[*j] != NULL)
	{
		while (data->map[*j][*i] != c && data->map[*j][*i] != '\0')
			*i = *i + 1;
		if (data->map[*j][*i] == c)
			return (1);
		*i = 0;
		*j = *j + 1;
	}
	return (0);
}

int	count_collect(char **map, int *nbcollect)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*nbcollect = 0;
	while (map[j] != NULL)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				*nbcollect = *nbcollect + 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (*nbcollect);
}

static void	ennemi_move2(t_data *data, t_en **temp, int l)
{
	t_en	*ptr;

	ptr = *temp;
	if (data->map[ptr->j][ptr->i + l] == 'P')
	{
		printf(ENLOSE);
		end(data, 1);
	}
	if (data->map[ptr->j][ptr->i + l] == '0')
	{
		data->map[ptr->j][ptr->i] = '0';
		data->map[ptr->j][ptr->i + l] = '3';
		if (ptr->boolean_direction == 1)
			ptr->i++;
		else if (ptr->boolean_direction == 2)
			ptr->i--;
	}
	else
	{
		if (l == 1)
			ptr->boolean_direction = 2;
		else
			ptr->boolean_direction = 1;
	}
}

int	ennemi_move(t_data *data, t_en **temp)
{
	t_en	*ptr;
	int		i;
	int		j;

	ptr = *temp;
	if (find_letter(data, '3', &i, &j) != 1)
		return (0);
	while (ptr != NULL)
	{
		if (data->map[ptr->j][ptr->i] == 'P')
			ptr->live = 0;
		if (ptr->live != 0)
		{
			if (ptr->boolean_direction == 1)
				ennemi_move2(data, &ptr, 1);
			else
				ennemi_move2(data, &ptr, -1);
		}
		ptr = ptr->next;
	}
	return (1);
}
