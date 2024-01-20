/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:58:44 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 11:13:44 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point **ft_isometric_projection(t_map **matrix, t_fdf *data)
{
    int i = 0;
    int j = 0;
    t_point **matrix_2D;
    double alpha = M_PI / 4;
    matrix_2D = malloc(sizeof(t_point *) * (data->map->lenght));
    if (!matrix_2D)
        exit(0);
    i = -1;
    while (++i < data->map->lenght)
        matrix_2D[i] = malloc(sizeof(t_point) * (data->map->with));
    i = 0;
    while(i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            matrix_2D[i][j].x = (matrix[i][j].x * cos(alpha) - matrix[i][j].y * sin(alpha)) / sqrt(2);
            matrix_2D[i][j].y = (matrix[i][j].x * sin(alpha) + matrix[i][j].y * sin(alpha)) / sqrt(2);
            matrix_2D[i][j].z = matrix[i][j].z;
            matrix_2D[i][j].color = matrix[i][j].color;
            j++;
        }
        i++;
    }
    return (matrix_2D);
}

t_point **ft_iso_3d(t_point **matrix, t_fdf *data)
{
    int i = 0;
    int j = 0;
    double alpha = 0.9252455;
    i = 0;
    while(i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {   
            matrix[i][j].x = matrix[i][j].x ;
            matrix[i][j].y = (matrix[i][j].y * cos(alpha) - matrix[i][j].z * sin(alpha)) /sqrt(2);
            matrix[i][j].z = matrix[i][j].z;
            matrix[i][j].color = matrix[i][j].color;
            j++;
        }
        i++;
    } 
    return (matrix);
}
