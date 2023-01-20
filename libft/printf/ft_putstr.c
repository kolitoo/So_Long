/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:37:19 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/17 13:37:29 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		*len = *len + 6;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
}
