/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:19 by mfarhat           #+#    #+#             */
/*   Updated: 2024/03/03 13:56:37 by mfarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H
# define FT_TOOLS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define DICT_REF "resources/numbersEN.dict"
# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"

typedef struct s_dict
{
	char	*value;
	char	*wrt;
}				t_dict;

typedef struct s_trio
{
	char	*hundred_units;
	char	*hundred;
	char	*dozen;
	char	*unit;
}				t_trio;

void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_putchar(char c);
int				error(char *err);

char			*ft_strdup(char *src, int pos, int size);
char			**ft_split(char *str, char *charset);
char			**ft_split_mod(char *str, char *charset);
void			ft_free_split(char **tab);
int				ft_is_charset(char *src, int pos, char *charset);
int				ft_wrdlen(char *str, int pos, char *charset);

t_dict			*ft_dict_parsing(int size, char **dict);
int				ft_dictmaxlen(t_dict *dict);
t_dict			*ft_dict_setup(char *dict_path);
void			ft_free_dict(t_dict *dict);

int				ft_strcmp(char *s1, char *s2);

char			**get_lines_from_dict(char *path_to_dict);
int				get_number_of_lines(char **lines);
char			*ft_file_missing(void);

char			*format_string(char *str);
t_trio			*trio_to_struct(char *str);
void			free_trio(t_trio *trio);

int				ft_display_zero(int n, t_dict *dict);
void			ft_display_hundred_units(char *str, t_dict *dict, int *f);
void			ft_display_hundred(char *str, t_dict *dict, int *f);
void			ft_display_dozen(char *str, t_dict *dict, int *f);
void			ft_display_unit(char *str, t_dict *dict, int *f);

#endif
