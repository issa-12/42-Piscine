/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:17:19 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/15 16:25:28 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_helper(int nb)
{
	char	digit;
	int		var;

	if (nb != 0)
	{	
		var = nb % 10;
		nb /= 10;
		ft_putnbr_helper(nb);
		digit = var + '0';
		write(1, &digit, 1);
	}
}

void	ft_putnbr(int number)
{
	if (number == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr_helper(147483648);
		return ;
	}
	if (number == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (number < 0)
	{
		write(1, "-", 1);
		number = -1 * number;
	}
	ft_putnbr_helper(number);
}
