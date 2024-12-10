/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:45:06 by mfarhat           #+#    #+#             */
/*   Updated: 2024/03/03 14:45:11 by mfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tools.h>

char	*ft_strdup(char *src, int pos, int size)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*dest) * (size + 1));
	if (!(dest))
		return (0);
	while (i < size)
	{
		dest[i] = src[pos + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_charset(char *src, int pos, char *charset)
{
	int	i;

	i = 0;
	while (i < ft_strlen(charset))
	{
		if (src[pos] == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_wrdlen(char *str, int pos, char *charset)
{
	int	i;

	i = 0;
	while (str[pos + i] != '\0' && ft_is_charset(str, (pos + i), charset) == 1)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		compteur;
	int		size;

	compteur = 0;
	i = 0;
	split = malloc(sizeof(*split) * (ft_strlen(str) + 1));
	if (!(split))
		return (0);
	while (i < ft_strlen(str))
	{
		if (ft_is_charset(str, i, charset) == 1)
		{
			size = ft_wrdlen(str, i, charset);
			split[compteur] = ft_strdup(str, i, size);
			i = i + size;
			compteur = compteur + 1;
		}
		i++;
	}
	split[compteur] = 0;
	return (split);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		free(tab[i++]);
	free(tab);
}
