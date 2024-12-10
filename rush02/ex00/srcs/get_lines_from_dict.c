/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_from_dict.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:48:48 by mfarhat           #+#    #+#             */
/*   Updated: 2024/03/03 23:31:40 by mkaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tools.h>

char	*ft_file_missing(void)
{
	char	buf;
	char	buffer[29000];
	int		rd;
	char	*ptr;

	rd = 0;
	while (read(1, &buf, 1) != 0)
	{
		if (buf != '\n')
		{
			buffer[rd] = buf;
			rd++;
		}
		else
			break ;
	}
	buffer[rd] = '\0';
	ptr = &buffer[0];
	return (ptr);
}

int	error(char *err)
{
	ft_putstr(err);
	return (0);
}

char	*filetostr(char *path)
{
	int				dict;
	unsigned int	nbchars;
	char			currchar;
	char			*filestr;
	int				i;

	dict = open(path, O_RDONLY);
	if ((dict) < 0)
		return (NULL);
	nbchars = 0;
	while (read(dict, &currchar, 1))
		nbchars++;
	filestr = malloc(sizeof(*filestr) * (nbchars + 1));
	if (!(filestr))
		return (NULL);
	close(dict);
	dict = open(path, O_RDONLY);
	i = 0;
	while (read(dict, filestr + i, 1))
		i++;
	close(dict);
	filestr[nbchars] = '\0';
	return (filestr);
}

char	**get_lines_from_dict(char *path_to_dict)
{
	char	**lines;
	char	*filestr;

	filestr = filetostr(path_to_dict);
	if (!(filestr))
		return (NULL);
	lines = ft_split(filestr, "\n");
	free(filestr);
	return (lines);
}

int	get_number_of_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}
