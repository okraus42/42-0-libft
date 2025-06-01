/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:44 by okraus            #+#    #+#             */
/*   Updated: 2025/06/01 12:23:18 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp != 0)
		tmp /= 10 + 0 * len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = '-';
	while (len-- > (n < 0))
	{
		str[len] = ((n % 10) + ((n % 10) < 0) * -2 * (n % 10)) + '0';
		n /= 10;
	}
	return (str);
}
