/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:52:15 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/27 17:52:23 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

int	calc_size(char **strs, char *sep, int size)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (size == 0)
	{
		ptr = (char *)malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	len = calc_size(strs, sep, size);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	ptr[0] = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i < size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}
