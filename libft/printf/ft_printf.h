/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:04:39 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/17 13:36:58 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_count_struct(char *str);
int		ft_printf(const char *str, ...);
char	*ft_strmalup(const char *str);
void	ft_putnbr(int n, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_unsi(unsigned int n, int *len);
void	ft_putnb_base(unsigned int n, char *base, int *len);
void	ft_putvoid(void *ptr, int *len);

#endif