/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:02:39 by okraus            #+#    #+#             */
/*   Updated: 2025/05/27 18:42:46 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	uint8_t		*ptr8;
	uintptr_t	addr;
	uint64_t	*ptr64;

	ptr8 = (uint8_t *)s;
	addr = (uintptr_t)ptr8;
	while (n > 0 && (addr % 8 != 0))
	{
		*ptr8++ = 0;
		n--;
		addr++;
	}
	ptr64 = (uint64_t *)ptr8;
	while (n >= 8)
	{
		*ptr64++ = 0;
		n -= 8;
	}
	ptr8 = (uint8_t *)ptr64;
	while (n--)
	{
		*ptr8++ = 0;
	}
}
