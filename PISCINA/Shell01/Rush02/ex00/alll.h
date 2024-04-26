/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:22:06 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 23:15:00 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLL_H
# define ALLL_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		length;
	char	*number;
	char	*word;
}			t_map;

char		*check_param(int agrc, char **argv);

int			file_read(char *dic_name);

int			check_num(char *str);

int			ft_strlen(char *str);

void		ft_putstr(char *str);

int			file_valid(char *dic_name, t_map map[100]);

int			fill_map(t_map *map, char *line);

char		*ft_strncpy(char *dest, char *src, unsigned int n);

void		imprimir_mapa(t_map *map);

int			len(long nb);

char		*ft_itoa(int nb);

int			ft_atoi(const char *str);

void		print_number(char *num, t_map *map);

int			ft_strncmp(char *s1, char *s2, unsigned int n);

void		imprimir_mapa(t_map *map);

char		*ft_charcat(char dest, char src);

int			print_lastname(const t_map *map, int len, int size);

char		*ft_strcat(char *dest, char *src);

void		printing(char *num, t_map *map);

void		printing2(char *third, char *filled_num, t_map *map, int len);

void		main2(t_map *map, char *num);
#endif
