/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:50:46 by abourdon          #+#    #+#             */
/*   Updated: 2023/01/17 16:38:37 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t elemCount, size_t elementSize)
{
	void	*tab;
	char	*array;
	size_t	i;

	i = 0;
	tab = NULL;
	if (elemCount * elementSize == 0 || elemCount <= SIZE_MAX / elementSize)
		tab = (void *)malloc(elemCount * elementSize);
	if (!tab)
		return (NULL);
	array = (char *) tab;
	while (i < elemCount * elementSize)
	{
		array[i] = 0;
		i++;
	}
	return (tab);
}
