/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:03:37 by okraus            #+#    #+#             */
/*   Updated: 2023/01/11 16:03:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
