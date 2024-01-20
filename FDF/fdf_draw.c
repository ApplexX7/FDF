/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:05:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 10:02:10 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_put_pixels(t_img *img, int x, int y, int color)
{
    char *offset;

    if ((0 < x && x < WIDTH) && (0 < y && y < LENGHT))
    {
        offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
        *(unsigned int *) (offset) = color;
    }
}

t_point **centred_point(t_point **matrix, t_fdf *data)
{
    int i;
    int j;

    data->scal = round(fmax(WIDTH / data->map->with / 2, LENGHT / data->map->lenght / 2));
    double square_x = (WIDTH / 2);
    double square_y = (LENGHT / 2);
    int x1 = (square_x + 300) / 2 - data->map->with / 2;
    int y1 = (square_y  + 300) / 2 - data->map->lenght / 2;
    i = 0;
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            matrix[i][j].x = round(x1 +  matrix[i][j].x * data->scal);
            matrix[i][j].y = round(y1 + matrix[i][j].y * data->scal);
            j++;
        }
        i++;
    }
    return(matrix);
}

void destroy_matrix(t_map **matrix, t_fdf *data)
{
    int i;

    i = 0;
    while (i < data->map->lenght)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void free_matrix(t_point **matrix, t_fdf *data)
{
    int i;

    i = 0;
    while (i < data->map->lenght)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void draw_projects(t_fdf *data, t_map **matrix_3D)
{
    int x;
    int y;
    t_point **matrix;

    y = 0;
    matrix = ft_isometric_projection(matrix_3D, data);
    destroy_matrix(matrix_3D, data);
    matrix = ft_iso_3d(matrix , data);
    matrix = centred_point(matrix, data);
    while (y < data->map->lenght - 1)
    {
        x = 0;
        while (x < data->map->with - 1)
        {
            brehensman_algo(matrix[y][x], matrix[y][x + 1], data);
            brehensman_algo(matrix[y][x], matrix[y + 1][x], data);
            if (y < data->map->lenght - 1)
            {
                brehensman_algo(matrix[y + 1][x], matrix[y + 1][x + 1], data);
                brehensman_algo(matrix[y][x + 1], matrix[y + 1][x + 1], data);
            }
            x++;
        }
        y++;
    }
    free_matrix(matrix, data);
}
