/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:23:38 by okraus            #+#    #+#             */
/*   Updated: 2025/06/03 18:32:50 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	uint8_t			*d8;
	const uint8_t	*s8;
	uint64_t		*d64;
	const uint64_t	*s64;

	d8 = (uint8_t *)dest;
	s8 = (const uint8_t *)src;
	while (n > 0 && ((uintptr_t)d8 % 8 != 0))
	{
		*d8++ = *s8++;
		n--;
	}
	d64 = (uint64_t *)d8;
	s64 = (const uint64_t *)s8;
	while (n >= 8)
	{
		*d64++ = *s64++;
		n -= 8;
	}
	d8 = (uint8_t *)d64;
	s8 = (const uint8_t *)s64;
	while (n--)
		*d8++ = *s8++;
	return (dest);
}
