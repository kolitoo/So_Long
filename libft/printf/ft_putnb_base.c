/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:34:42 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/17 13:37:04 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb_base(unsigned int n, char *base, int *len)
{
	if (n > 15)
	{
		ft_putnb_base(n / 16, base, len);
	}
	ft_putchar(base[n % 16], len);
}
