/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:48:41 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/20 19:20:44 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
