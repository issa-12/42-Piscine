/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:16:43 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/18 10:35:28 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	hex[2];

	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
		{
			write(1, str, 1);
		}
		else
		{
			write(1, "\\", 1);
			hex[0] = "0123456789abcdef"[(*str >> 4) & 0x0F];
			hex[1] = "0123456789abcdef"[*str & 0x0F];
			write(1, hex, 2);
		}
		str++;
	}
}
