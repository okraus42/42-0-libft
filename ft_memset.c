/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:01 by okraus            #+#    #+#             */
/*   Updated: 2025/05/27 18:48:28 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t n)
{
	uint8_t		*ptr8;
	uintptr_t	addr;
	uint64_t	*ptr64;
	uint64_t	fill;

	ptr8 = (uint8_t *)s;
	addr = (uintptr_t)ptr8;
	fill = (uint8_t)c << 8 | (uint8_t)c;
	fill |= fill << 16;
	fill |= fill << 32;
	while (n > 0 && (addr % 8 != 0))
	{
		*ptr8++ = (uint8_t)c;
		n--;
		addr++;
	}
	ptr64 = (uint64_t *)ptr8;
	while (n >= 8)
	{
		*ptr64++ = fill;
		n -= 8;
	}
	ptr8 = (uint8_t *)ptr64;
	while (n--)
		*ptr8++ = (uint8_t)c;
	return (s);
}
