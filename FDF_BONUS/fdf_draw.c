/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:05:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 20:21:10 by mohilali         ###   ########.fr       */
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
void get_zmax(t_fdf *data)
{
    int i;
    int j;

    i = 0;
    data->Z_max = data->mat[0][0].z;
    while(i < data->map->lenght)
    {
        j = 0;
        while(j < data->map->with)
        {
            if (data->mat[i][j].z > data->Z_max)
                data->Z_max = data->mat[i][j].z;
            j++;
        }
        i++;
    }
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

void ft_iniate_coordonnes(t_fdf *data)
{
    int i;
    int j;
    
    if (data->zoom > 0)
        data->scal = round(fmin(WIDTH / data->map->with / 2, LENGHT / data->map->lenght / 2)) +  data->zoom;
    else
    {
        data->scal = round(fmin(WIDTH / data->map->with / 2, LENGHT / data->map->lenght / 2));
        data->zoom = 0;
    }
    double square_x = 0;
    double square_y = 0;
    i = 0;
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            square_x = (data->map->with * data->scal) / 2;
            square_y = (data->map->lenght * data->scal) / 2;
            data->mat[i][j].x = round(data->mat[i][j].x * data->scal - square_x);
            data->mat[i][j].y = round(data->mat[i][j].y * data->scal - square_y);
            data->mat[i][j].z = round(data->mat[i][j].z * data->scal);
            j++;
        }
        i++;
    }
}
void complite_centre(t_fdf *data)
{
    int j;
    int i;
    i = 0;
    get_zmax(data);
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            double square_x = (WIDTH / 2) + (data->translate.tran_x * data->scal);
            double square_y = ((LENGHT + data->Z_max) / 2) + (data->translate.tran_y * data->scal);
            data->mat[i][j].x = round(data->mat[i][j].x + square_x);
            data->mat[i][j].y = round(data->mat[i][j].y + square_y);
            data->mat[i][j].z = round(data->mat[i][j].z);
            j++;
        }
        i++;
    }
}

t_fdf *get_default_color(t_fdf *data)
{
    int i;
    int j;
    
    i = 0;
    while (i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {
            if (data->mat[i][j].z > 0)
                data->mat[i][j].color += data->change_color;
            else
                data->mat[i][j].color -= data->change_color;
            j++;
        }
        i++;
    }
    return (data);
}

void draw_projects(t_fdf *data, t_map **matrix_3D)
{
    int x;
    int y;
    
    y = -1;
    set_backgroud(data);
    data = copy_matrix(matrix_3D, data);
    ft_iniate_coordonnes(data);
    data = get_default_color(data);
    data = ft_xrotation(data);
    data = ft_yrotation(data);
    data = ft_zrotation(data);
    data = ft_isometric_projection(data);
    complite_centre(data);
    while (++y < data->map->lenght - 1)
    {
        x = -1;
        while (++x < data->map->with - 1)
        {
            brehensman_algo(data->mat[y][x], data->mat[y][x + 1], data);
            brehensman_algo(data->mat[y][x], data->mat[y + 1][x], data);
            brehensman_algo(data->mat[y + 1][x], data->mat[y + 1][x + 1], data);
            brehensman_algo(data->mat[y][x + 1], data->mat[y + 1][x + 1], data);
        }
    }
    free_matrix(data->mat, data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
}
