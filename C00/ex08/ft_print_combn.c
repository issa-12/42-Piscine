/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:18:34 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/15 14:38:51 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int*combination, int n)
{	
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = combination[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	generate_combinations(int n, int start, int index, int*arr)
{
	int		i;
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	i = start;
	if (index == n)
	{
		print_combination(arr, n);
		if (arr[0] != 10 - n)
		{
			write(1, &comma, 1);
			write(1, &space, 1);
		}
		return ;
	}
	while (i <= 9)
	{
		arr[index] = i;
		generate_combinations(n, i + 1, index + 1, arr);
		i++;
	}	
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	generate_combinations(n, 0, 0, arr);
}
