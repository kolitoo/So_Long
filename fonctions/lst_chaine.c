/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chaine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:40:04 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/19 16:33:38 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_en	*ft_lstnew(int i, int j, int live, int boolean)
{
	t_en	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->i = i;
	lst->j = j;
	lst->live = live;
	lst->boolean_direction = boolean;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_en **start, t_en *temp)
{
	t_en	*ptr;

	ptr = *start;
	if (start != NULL)
	{
		if (*start != NULL)
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = temp;
		}
		else
			*start = temp;
	}
}

void	ft_lstclear(t_en **lst)
{
	t_en	*ptr;

	if (lst != NULL)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			if (lst != NULL)
				free(*lst);
			(*lst) = ptr;
		}
	}
}

static t_en	*ft_lstremplir2(t_data *data, int i, int j, t_en *start)
{
	t_en	*temp;

	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == '3')
			{
				temp = ft_lstnew(i, j, 1, 1);
				if (!temp)
				{
					ft_lstclear(&temp);
					return (NULL);
				}
				ft_lstadd_back(&start, temp);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (start);
}

t_en	*ft_lstremplir(t_data *data)
{
	t_en	*start;
	int		i;
	int		j;

	find_letter(data, '3', &i, &j);
	start = ft_lstnew(i, j, 1, 1);
	if (!start)
	{
		ft_lstclear(&start);
		return (NULL);
	}
	i++;
	ft_lstremplir2(data, i, j, start);
	return (start);
}
