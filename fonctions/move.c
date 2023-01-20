/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:42:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/19 16:04:39 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	move_dir(t_data *data, int x, int y)
{
	if (data->map[data->ind.j + y][data->ind.i + x] != '1')
	{
		if (data->map[data->ind.j + y][data->ind.i + x] == 'E'
			&& data->count_collect == data->nbcollect)
			return (0);
		if (data->map[data->ind.j + y][data->ind.i + x] == 'C')
			collect_move(data);
		else
			data->boolean = 0;
		if (data->map[data->ind.j + y][data->ind.i + x] != 'E')
		{
			data->map[data->ind.j][data->ind.i] = '0';
			data->map[data->ind.j + y][data->ind.i + x] = 'P';
			data->count++;
		}
	}
	return (1);
}

int	move_updown(t_data *data, int keysym)
{
	int	d;
	int	u;

	d = 0;
	u = 0;
	find_letter(data, 'P', &data->ind.i, &data->ind.j);
	if (keysym == XK_s || keysym == XK_Down)
	{
		d = move_dir(data, 0, 1);
		if (d == 0)
			return (0);
	}
	if (keysym == XK_w || keysym == XK_Up)
	{
		u = move_dir(data, 0, -1);
		if (u == 0)
			return (0);
	}
	return (1);
}

int	move_rightleft(t_data *data, int keysym)
{
	int	l;
	int	r;

	l = 0;
	r = 0;
	find_letter(data, 'P', &data->ind.i, &data->ind.j);
	if (keysym == XK_a || keysym == XK_Left)
	{
		l = move_dir(data, -1, 0);
		if (l == 0)
			return (0);
		data->boolean2 = 1;
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		r = move_dir(data, 1, 0);
		if (r == 0)
			return (0);
		data->boolean2 = 2;
	}
	return (1);
}

int	move_player(t_data *data, int keysym)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	if (keysym == XK_a || keysym == XK_Left || keysym == XK_d
		|| keysym == XK_Right)
	{
		k = move_rightleft(data, keysym);
		if (k == 0)
			return (0);
	}
	if (keysym == XK_s || keysym == XK_Down || keysym == XK_w
		|| keysym == XK_Up)
	{
		l = move_updown(data, keysym);
		if (l == 0)
			return (0);
	}
	return (1);
}
