/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:13:46 by hsarraj           #+#    #+#             */
/*   Updated: 2024/02/18 19:38:52 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush03(int x, int y);

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	main(int ac, char *av[])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ac == 1)
	{
		rush03 (5, 3);
	}
	else
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[2]);
		rush03 (x, y);
	}
	return (0);
}
