/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsinno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:46:18 by rsinno            #+#    #+#             */
/*   Updated: 2024/02/25 20:46:36 by rsinno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	initialize_board(int *input);

int	is_valid_input_format(char *arg, int length, int *input)
{
	int	i_char_input;
	int	i_int_input;

	i_char_input = 0;
	i_int_input = 0;
	while (i_char_input < length)
	{
		if ((arg[i_char_input] >= '1' && arg[i_char_input] <= '4')
			&& ((arg[i_char_input + 1] == ' ')
				|| (arg[i_char_input + 1] == '\0')))
		{
			input[i_int_input] = arg[i_char_input] - '0';
			i_int_input++;
			i_char_input += 2;
		}
		else
			return (0);
	}
	return (1);
}

int	get_input_length(char *arg)
{
	int	count_chars_input;

	count_chars_input = 0;
	while (*arg != '\0')
	{
		count_chars_input++;
		arg++;
	}
	return (count_chars_input);
}

int	main(int argc, char **argv)
{
	int	input[16];
	int	length;

	if (argc == 2)
	{			
		length = get_input_length(argv[1]);
		if (length == 31)
		{
			if (is_valid_input_format(argv[1], length, input))
				initialize_board(input);
			else
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
