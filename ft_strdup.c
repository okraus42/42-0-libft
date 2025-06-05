/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:12:03 by okraus            #+#    #+#             */
/*   Updated: 2025/06/05 14:55:22 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	len = i;
	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	else
	{
		while (i < len)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}
