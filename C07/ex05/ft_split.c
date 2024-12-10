/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:36:25 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/27 15:36:35 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	total_words(char *charset, char *str)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_seperator(str[i + 1], charset) == 1
			&& check_seperator(str[i], charset) == 0)
		{
			total++;
		}
		i++;
	}
	return (total);
}

void	copy_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (check_seperator(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	do_split(char **array, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (check_seperator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (check_seperator(str[i + j], charset) == 0)
				j++;
			array[word] = (char *)malloc(sizeof(char) * (j + 1));
			copy_word(array[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		words;

	words = total_words(charset, str);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	array[words] = 0;
	do_split(array, str, charset);
	return (array);
}
