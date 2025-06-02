/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:39:11 by okraus            #+#    #+#             */
/*   Updated: 2025/06/02 15:44:11 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[16];
	int		len;
	int		tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp != 0)
		tmp /= 10 + 0 * len++;
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[0] = '-';
	while (len-- > (n < 0))
	{
		str[len] = ((n % 10) + ((n % 10) < 0) * -2 * (n % 10)) + '0';
		n /= 10;
	}
	write(fd, str, len);
}
