/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:01:06 by mfarhat           #+#    #+#             */
/*   Updated: 2024/03/03 14:37:23 by mfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tools.h>

char	*ft_rmv_spaces(char *str)
{
	int		i;
	char	*tab;
	int		j;
	int		k;

	tab = malloc(sizeof(*tab) * (ft_strlen(str) + 2));
	if (!(tab))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] == 32)
		i++;
	j = ft_strlen(str);
	while (j >= 0 && str[j] == 32)
		j++;
	k = 0;
	while (k < j - i + 1)
	{
		tab[k] = str[i + k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

t_dict	*ft_dict_parsing(int size, char **dict)
{
	int		i;
	t_dict	*dict_sct;
	char	**split_value;

	dict_sct = malloc(sizeof(*dict_sct) * (size + 1));
	if (!(dict_sct))
		return (NULL);
	i = 0;
	while (i < size)
	{
		split_value = ft_split_mod(dict[i], ":");
		if (split_value == 0)
			continue ;
		dict_sct[i].value = ft_rmv_spaces(split_value[0]);
		dict_sct[i].wrt = ft_rmv_spaces(split_value[1]);
		ft_free_split(split_value);
		i++;
	}
	dict_sct[i].value = 0;
	return (dict_sct);
}

int	ft_dictmaxlen(t_dict *dict)
{
	int	i;
	int	max;
	int	length;

	i = 0;
	max = 0;
	while (dict[i].value)
	{
		length = ft_strlen(dict[i].value);
		if (length > max)
			max = length;
		i++;
	}
	return (max + 2);
}

t_dict	*ft_dict_setup(char *dict_path)
{
	t_dict	*dict_sct;
	char	**dict_sub;
	int		dict_length;

	dict_sub = get_lines_from_dict(dict_path);
	if (!(dict_sub))
		return (NULL);
	dict_length = get_number_of_lines(dict_sub);
	dict_sct = ft_dict_parsing(dict_length, dict_sub);
	free(dict_sub);
	return (dict_sct);
}

void	ft_free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].value != 0)
	{
		free(dict[i].value);
		free(dict[i].wrt);
		i++;
	}
	free(dict);
}
