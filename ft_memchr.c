/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:37 by okraus            #+#    #+#             */
/*   Updated: 2025/06/05 14:51:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (c % 256) && i + 1 < n)
		i++;
	if (n == 0)
		return (NULL);
	if (str[i] == (c % 256))
		return (&str[i]);
	return (NULL);
}
