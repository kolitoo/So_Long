/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrackingC.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:13:10 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/20 12:57:10 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_map3(t_data *data, char *str)
{
	data->map = ft_split(str, '\n');
	if (!data->map)
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
	data->map_back = ft_split(str, '\n');
	if (!data->map_back)
	{
		free(str);
		free_map(data, data->map);
		exit(EXIT_SUCCESS);
	}
	data->mapcol = ft_split(str, '\n');
	if (!data->mapcol)
	{
		free(str);
		free_map(data, data->map);
		free_map(data, data->map_back);
		exit(EXIT_SUCCESS);
	}
}

static int	backtrack_move_col(char **ma, int j, int i)
{
	if (ma[j][i + 1] != '1' && ma[j][i + 1] != '2' && ma[j][i + 1] != 'E')
	{
		ma[j][i] = '2';
		return (1);
	}
	else if (ma[j + 1][i] != '1' && ma[j + 1][i] != '2' && ma[j + 1][i] != 'E')
	{
		ma[j][i] = '2';
		return (2);
	}
	else if (ma[j][i - 1] != '1' && ma[j][i - 1] != '2' && ma[j][i - 1] != 'E')
	{
		ma[j][i] = '2';
		return (3);
	}
	else if (ma[j - 1][i] != '1' && ma[j - 1][i] != '2' && ma[j - 1][i] != 'E')
	{
		ma[j][i] = '2';
		return (4);
	}
	else
	{
		ma[j][i] = '2';
		return (0);
	}
}

static int	backtrack_collect_condition(char **map_back, int j, int i, int dep)
{
	if (dep == 1)
	{	
		if (backtrack_col(map_back, j, i + 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_back, j, i);
	if (dep == 2)
	{
		if (backtrack_col(map_back, j + 1, i, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_back, j, i);
	if (dep == 3)
	{
		if (backtrack_col(map_back, j, i - 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_back, j, i);
	if (dep == 4)
	{
		if (backtrack_col(map_back, j - 1, i, dep) == 1)
			return (1);
	}
	return (0);
}

int	backtrack_col(char **map_backtrack_col, int j, int i, int dep)
{
	int	c;

	c = 0;
	dep = backtrack_move_col(map_backtrack_col, j, i);
	backtrack_collect_condition(map_backtrack_col, j, i, dep);
	if (count_collect(map_backtrack_col, &c) == 0)
		return (1);
	return (0);
}
