/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:18:58 by isalayan          #+#    #+#             */
/*   Updated: 2024/03/06 16:18:59 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_err(char c)
{
	write(2, &c, 1);
}

void	error(char *err)
{
	int	i;

	i = 0;
	while (err[i])
	{
		ft_putchar_err(err[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	n;

	nbr = 0;
	n = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return (nbr * n);
}
