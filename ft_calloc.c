/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:48:51 by okraus            #+#    #+#             */
/*   Updated: 2025/06/05 14:52:32 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr)
		ft_bzero(ptr, total);
	return (ptr);
}
