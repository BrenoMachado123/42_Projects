/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:08:12 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 15:31:06 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t mem, size_t size)
{
	char	*alloc;

	alloc = malloc(size * mem);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, size * mem);
	return (alloc);
}
