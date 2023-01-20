/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:09 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/19 16:22:40 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_elem(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] != 'E' && data->map[j][i]
				!= 'P' && data->map[j][i] != 'C' && data->map[j][i] != '3'
				&& data->map[j][i] != '1' && data->map[j][i]
				!= '0')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_elem_nb(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == c)
				count ++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count != 1 && (c == 'P' || c == 'E'))
		return (0);
	if (count < 1 && c == 'C')
		return (0);
	return (1);
}

int	check_map_rectangle(t_data *data)
{
	data->ind.i = 0;
	data->ind.j = 0;
	while (data->map[0][data->ind.i] != '\0')
	{
		if (data->map[0][data->ind.i++] != '1')
			return (0);
	}
	data->ind.k = data->ind.i;
	while (data->map[data->ind.j] != NULL)
	{
		if (data->map[data->ind.j++][0] != '1')
			return (0);
	}
	while (data->ind.k > 0)
	{
		if (data->map[data->ind.j - 1][--data->ind.k] != '1')
			return (0);
	}
	while (data->ind.j > 0)
	{
		if (data->map[--data->ind.j][data->ind.i - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_form_map(t_data *data)
{
	int	j;
	int	lenght;

	lenght = ft_strlenn(data->map[0]);
	j = 1;
	while (data->map[j] != NULL)
	{
		if ((int)ft_strlenn(data->map[j]) != lenght)
			return (0);
		j++;
	}
	return (1);
}

int	global_check(t_data *data)
{
	if (check_valid_elem(data) == 0)
	{
		ft_printf(ELEM_NON_VALIDE);
		end(data, 0);
	}
	if (check_elem_nb(data, 'P') == 0)
	{
		ft_printf(ERROR_C);
		end(data, 0);
	}
	if (check_elem_nb(data, 'E') == 0)
	{
		ft_printf(ERROR_NB_E);
		end(data, 0);
	}
	if (check_elem_nb(data, 'C') == 0)
	{
		ft_printf(ERROR_NB_C);
		end(data, 0);
	}
	return (1);
}
