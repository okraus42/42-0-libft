/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:36 by okraus            #+#    #+#             */
/*   Updated: 2025/06/05 14:56:10 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char const *str);

// static inline int	ft_check_separator(char const s, char const c)
// {
// 	if (s == c)
// 		return (1);
// 	return (0);
// }

static int	ft_count_strings(char const *s, char const c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_move_pointer(char **dst, char d, int *in_word, int i)
{
	**dst = d;
	(*dst)++;
	*in_word = i;
}

static void	ft_fill_words(char **result, char const *s, char c)
{
	char	*buf;
	char	*dst;
	int		i;
	int		in_word;
	int		idx;

	buf = (char *)(result + ft_count_strings(s, c) + 1);
	dst = buf;
	i = 0;
	in_word = 0;
	idx = 0;
	while (s[i] || in_word)
	{
		if (s[i] && s[i] != c)
		{
			if (!in_word)
				result[idx++] = dst;
			ft_move_pointer(&dst, s[i], &in_word, 1);
		}
		else if (in_word)
			ft_move_pointer(&dst, '\0', &in_word, 0);
		i++;
	}
	result[idx] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	size_t	s_len;
	size_t	total_size;

	if (!s)
		return (NULL);
	words = ft_count_strings(s, c);
	s_len = ft_strlen(s);
	total_size = sizeof(char *) * (words + 1) + s_len + 1;
	result = malloc(total_size);
	if (result)
		ft_fill_words(result, s, c);
	return (result);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 		return (1);
// 	char **split = ft_split(argv[1], argv[2][0]);
// 	for (int i = 0; split[i]; i++)
// 		printf("split[%d]: %s\n", i, split[i]);
// 	free(split);
// 	return (0);
// }
