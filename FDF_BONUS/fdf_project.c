/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:58:44 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 20:53:59 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf *copy_matrix(t_map **matrix, t_fdf *data)
{
    int i = 0;
    int j = 0;
    t_point **matrix_2D;
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
            matrix_2D[i][j].x = matrix[i][j].x;
            matrix_2D[i][j].y =  matrix[i][j].y;
            if (matrix[i][j].z > 0)
                matrix_2D[i][j].z = (matrix[i][j].z + data->change_altitude);
            else
            {
                matrix_2D[i][j].z = matrix[i][j].z;
                // data->change_altitude = 1;
            }
            matrix_2D[i][j].color = matrix[i][j].color;
            j++;
        }
        i++;
    }
    data->mat = matrix_2D;
    return (data);
}


t_fdf *ft_isometric_projection(t_fdf *data)
{
    int i = 0;
    int j = 0;
    double x;
    double alpha = M_PI / 4;
    double beta = 0.615472907;
    i = 0;
    while(i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            x = data->mat[i][j].x;
            data->mat[i][j].x = data->mat[i][j].x * cos(beta) - data->mat[i][j].y * sin(beta);
            data->mat[i][j].y = data->mat[i][j].y * cos(alpha) + x * sin(alpha) - data->mat[i][j].z;
            data->mat[i][j].z = data->mat[i][j].z;
            j++;
        }
        i++;
    }
    return (data);
}

t_fdf *ft_xrotation(t_fdf *data)
{
    int i = 0;
    int j = 0;
    double y;
    double alpha = 0 + data->fdf.x_rot;
    i = 0;
    while(i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {   
            y = data->mat[i][j].y;
            data->mat[i][j].x = data->mat[i][j].x;
            data->mat[i][j].y = (data->mat[i][j].y * cos(alpha) - data->mat[i][j].z * sin(alpha));
            data->mat[i][j].z = (data->mat[i][j].z * cos(alpha) + y * sin(alpha));
            data->mat[i][j].color = data->mat[i][j].color;
            j++;
        }
        i++;
    } 
    return (data);
}
t_fdf *ft_yrotation(t_fdf *data)
{
    int i;
    int j;
    double alpha = 0 + data->fdf.y_rot;
    double x;
    i = 0;
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            x = data->mat[i][j].x;
            data->mat[i][j].x = data->mat[i][j].x * cos(alpha) + data->mat[i][j].z * sin(alpha);
            data->mat[i][j].y = data->mat[i][j].y;
            data->mat[i][j].z = data->mat[i][j].z *cos(alpha) - x * sin(alpha);
            j++;
        }
        i++;
    }
    return (data);
}

t_fdf *ft_zrotation(t_fdf *data)
{
    int i;
    int j;
    double alpha = -1.5708 + data->fdf.z_rot;
    double x;

    i = 0;
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            x = data->mat[i][j].x;
            data->mat[i][j].x = data->mat[i][j].x * cos(alpha) - data->mat[i][j].y * sin(alpha);
            data->mat[i][j].y = data->mat[i][j].y * cos(alpha) + x * sin(alpha);
            data->mat[i][j].z = data->mat[i][j].z;
            j++;
        }
        i++;
    }
    return(data);
}
