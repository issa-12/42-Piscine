/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:12 by hsarraj           #+#    #+#             */
/*   Updated: 2024/02/18 19:00:09 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

int	ne_to_po(int v)
{		
	v = -v;
	return (v);
}

void	processing(int x, int y, int i)
{
	int	j;

	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((i == 0 && j == 0) || (i == y - 1 && j == 0))
				ft_putchar('A');
			else if ((i == 0 && j == x - 1) || (i == y - 1 && j == x - 1))
				ft_putchar('C');
			else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	rush03(int x, int y)
{
	int	i;

	i = 0;
	if (x < 0)
		x = ne_to_po(x);
	if (y < 0)
		y = ne_to_po(y);
	processing(x, y, i);
}
