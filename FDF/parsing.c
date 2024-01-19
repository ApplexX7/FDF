/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:31:05 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/19 16:04:54 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_free(char **arr)
{
	int len;

	len = 0;
	if (!arr)
		return ;
	while (arr[len] != NULL)
	{
		free(arr[len]);
		len++;
	}
	free(arr);
	arr = NULL;	
}

size_t len_withd(char **str)
{
	int len;
	
	len = 0;
	while(str[len])
		len++;
	return (len);
}
void check_len_line(size_t len, int fd, char *str)
{
	char **arr;

	while (str)
	{
		arr = ft_split(str, ' ');
		if (!arr)
			free(str), exit(0);
		if (len_withd(arr) < len)
		{
			write(2, "Found line lenght Error!\n", 25);
			free(str);
			ft_free(arr);
			exit(0);
		}
		free(str);
		ft_free(arr);
		str = get_next_line(fd);
	}
	free(str);
}

int ft_get_with(char *av)
{
	int fd;
	char *str;
	char **par;
	size_t len;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(write(2, "Error : can't open the file!\n", 29), exit (0));
	str = get_next_line(fd);
	if (!str)
		(perror("not data found!"), exit(0));
	par = ft_split(str, ' ');
	if (!par)
		close(fd), exit(0);
	len = len_withd(par);
	check_len_line(len, fd, str);
	if (close(fd) == -1)
		(perror(strerror(errno)), exit(0));
	ft_free(par);
	return (len);
}
int ft_get_lenght(char *av)
{
	int len;
	int fd;
	char *str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(write(2, "Error : can't open the file!\n", 29), exit (0));
	str = get_next_line(fd);
	if (!str)
		(perror("not data found!"), exit(0));
	len = 0;
	while(str)
	{
		if (str[0] == '\n' || str[0] == '\0')
			(write(2, "Found a wrong line in the map!\n", 31), exit(0));
		free(str);
		len++;
		str = get_next_line(fd);
	}
	free(str);
	if (close(fd) == -1)
		(perror(strerror(errno)), exit(0));
	return (len);
}

t_map **get_coordonnes(char *av, int len, int with)
{
	int fd;
	char **str;
	int i = 0;
	int j = 0;
	char *s;
	t_map **matrix;
	char **split;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(0);
	matrix = malloc(sizeof(t_map*) * len + 1);
	if (!matrix)
		exit(0);
	s = get_next_line(fd);
	str = ft_split(s, ' ');
	while (i < len && str != NULL)
	{
		matrix[i] = malloc(sizeof(t_map) * with);
		j = 0;
		while(j < with && str[j])
		{
			matrix[i][j].x = j;
			matrix[i][j].y = i;
			if (ft_strchr(str[j], ','))
			{
				split = ft_split(str[j], ',');
				matrix[i][j].z = ft_atoi(split[0]);
				matrix[i][j].color = atoi_base(split[1], "0123456789ABCDEF");
				ft_free(split);
			}
			else
			{
				matrix[i][j].z = ft_atoi(str[j]);
				if (matrix[i][j].z > 0)
					matrix[i][j].color  = 0x80ffdb;
				else
				matrix[i][j].color = 0x00a8e8;
			}
			j++;
		}
		ft_free(str);
		free(s);
		s = get_next_line(fd);
		str = ft_split(s, ' ');
		i++;
	}
	ft_free(str);
	free(s);
	close(fd);
	return (matrix);
}

t_map **handling_parsing(char *av, t_fdf *env)
{
	t_map **matrix;
	env->map->lenght = ft_get_lenght(av);
	env->map->with = ft_get_with(av);
	matrix = get_coordonnes(av, env->map->lenght, env->map->with);
	return (matrix);
}
