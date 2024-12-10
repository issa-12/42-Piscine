/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsinno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:45:09 by rsinno            #+#    #+#             */
/*   Updated: 2024/02/25 21:45:12 by rsinno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_board(int board[4][4], int *input);

int	find_empty_boxes(int board[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int	is_unique_in_column(int board[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	is_unique_in_row(int board[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	is_unique_in_row_and_column(int board[4][4], int row, int col, int num)
{
	if ((is_unique_in_row(board, row, num))
		&& (is_unique_in_column(board, col, num))
		&& (board[row][col] == 0))
		return (1);
	return (0);
}

int	fill_empty_boxes_back_track(int board[4][4], int *input)
{
	int	row;
	int	col;
	int	num;

	num = 1;
	if (!(find_empty_boxes(board, &row, &col))
		&& (check_board(board, input) == 1))
		return (1);
	while (num <= 4)
	{
		if (is_unique_in_row_and_column(board, row, col, num))
		{
			board[row][col] = num;
			if (fill_empty_boxes_back_track(board, input) == 1)
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}
