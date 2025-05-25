/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:42:25 by okraus            #+#    #+#             */
/*   Updated: 2025/05/24 18:21:31 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	const char			*s;
	const unsigned long	*lw_ptr;
	unsigned long		lw;

	s = str;
	while (((unsigned long)s & (sizeof(unsigned long) - 1)) != 0 && *s)
		s++;
	lw_ptr = (const unsigned long *)s;
	while (1)
	{
		lw = *lw_ptr;
		if (((lw - 0x0101010101010101UL) & ~lw & 0x8080808080808080UL) != 0)
		{
			s = (const char *)lw_ptr;
			while (*s)
				++s;
			return (s - str);
		}
		lw_ptr++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i\n", ft_strlen(""));
// 	printf("%i\n", ft_strlen("0"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa51"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa512"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa5123"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa51234"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa512345"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa5123456"));
// 	printf("%i\n", ft_strlen("aaaa5aaaa51234567"));
// 	printf("%i\n", ft_strlen("lorem\tipsum\tdolor\nsit\namet\n"));
// 	return (0);
// }
