/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:10:14 by okraus            #+#    #+#             */
/*   Updated: 2025/06/05 14:55:22 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j) < len && little[j] && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
