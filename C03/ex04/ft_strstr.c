/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:45:46 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/19 17:28:22 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*p_str;
	char	*p_to_find;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		p_str = str;
		p_to_find = to_find;
		while (*p_to_find != '\0' && *p_str == *p_to_find)
		{
			p_str++;
			p_to_find++;
		}
		if (*p_to_find == '\0')
			return (str);
		str++;
	}
	return (NULL);
}
