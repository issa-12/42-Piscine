/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:58:02 by isalayan          #+#    #+#             */
/*   Updated: 2024/02/23 11:49:03 by isalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

void	ft_print_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = i;
		while (ft_strcmp(argv[j], argv[j - 1]) < 0 && j > 1)
		{
			tmp = argv[j - 1];
			argv[j - 1] = argv[j];
			argv[j] = tmp;
			j--;
		}
		i++;
	}
	ft_print_args(argc, argv);
	return (0);
}
