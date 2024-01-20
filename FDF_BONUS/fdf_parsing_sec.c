/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_sec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:33:40 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 20:17:01 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void complite_the_work(t_map **matrix, char **str, int i, int j)
{
    char **split;
    
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
        matrix[i][j].color  = 0;
		if (matrix[i][j].z > 0)
			matrix[i][j].color  = 0x80ffdb;
		else
			matrix[i][j].color = 0x00a8e8;
	}
}

t_map **get_matrix(t_fdf *data, char **str, int fd, char *s)
{
    int i = 0;
    int j;
    t_map **matrix;
    
    matrix = malloc(sizeof(t_map*) * data->map->lenght + 1);
    while (i < data->map->lenght && str != NULL)
	{
		matrix[i] = malloc(sizeof(t_map) * data->map->with);
		j = 0;
		while(j < data->map->with && str[j])
		{
            complite_the_work(matrix, str, i, j);
			j++;
		}
		ft_free(str);
		free(s);
		s = get_next_line(fd);
		str = ft_split(s, ' ');
		i++;
	}
    return (matrix);
}

t_map **get_coordonnes(char *av, t_fdf *data)
{
	int fd;
	char **str;
	char *s;
	t_map **matrix;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(0);
	s = get_next_line(fd);
    if (!s)
        write(2, "No data was found!!\n", 20);
	str = ft_split(s, ' ');
    if (!str)
        free(s),exit(0);
    matrix = get_matrix(data, str, fd, s);
	close(fd);
	return (matrix);
}
