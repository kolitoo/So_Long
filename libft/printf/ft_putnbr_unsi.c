/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:37:09 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/17 13:37:34 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsi(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr_unsi(n / 10, len);
	}
	ft_putchar((n % 10) + 48, len);
}
