/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:55:35 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/20 20:22:46 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	int	val;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
	{
		val = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (val);
	}
}
