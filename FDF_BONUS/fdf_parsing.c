/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:31:05 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 19:45:27 by mohilali         ###   ########.fr       */
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

t_fdf *handling_parsing(char *av, t_fdf *env)
{
	t_map **matrix;
	env->map->lenght = ft_get_lenght(av);
	env->map->with = ft_get_with(av);
	matrix = get_coordonnes(av, env);
	env->matrix = matrix;
	return (env);
}
