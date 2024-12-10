/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:17:15 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/26 14:42:17 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned int	get_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*str_cpy(char *str, char *dest)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*dest;

	i = get_len(src);
	dest = (char *)malloc(sizeof(char) * i);
	if (!(dest))
		return (NULL);
	return (str_cpy(src, dest));
}
