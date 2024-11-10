/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:25 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/07 23:21:51 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && c != '\0')
			i++;
	}
	return (word_count);
}

static int	writew(size_t k, size_t i, char *ptr, const char *s)
{
	size_t	l;

	l = 0;
	i -= k;
	while (l < k)
		ptr[l++] = s[i++];
	ptr[k] = '\0';
	return (i);
}

static char	**ft_write(const char *s, char **ptr, size_t word_count, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (c != '\0' && s[i] == c)
		i++;
	while (j < word_count)
	{
		k = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			k++;
		}
		ptr[j] = (char *)malloc((k + 1) * sizeof(char));
		if (ptr[j] == NULL)
			return (NULL);
		i = writew(k, i, ptr[j], s);
		while (s[i] == c && c != '\0')
			i++;
		j++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	no_of_words;

	if (!s)
		return (NULL);
	no_of_words = ft_word_count(s, c);
	ptr = (char **)malloc((no_of_words + 1) * sizeof(char *));
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr = ft_write(s, ptr, no_of_words, c);
	ptr[no_of_words] = NULL;
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**p;
	char 	*a = " tripouille  42  ";
	char	s = ' ';
	
	p = ft_split(a, s);
	for(int i = 0; i < 3; i++)
		printf("%s\n", p[i]);
}*/