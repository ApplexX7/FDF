/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:05:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/19 17:12:20 by mohilali         ###   ########.fr       */
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

// void brehensman_algo(int x1, int x2, int y1, int y2, t_fdf *data, int color)
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         my_mlx_put_pixels(data->img, x1, y1, color);
//         if (x1 == x2 && y1 == y2) {
//             break;
//         }
//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }


// void get_scale(t_fdf *data)
// {
//     t_scale *scal;

//     malloc();
//     scal
// }

int color(int c1, int c2, double per)
{
    return (c1 + (c2 - c1) * per);
}

unsigned int get_color(int c1, int c2, double per)
{
    int red;
    int blue;
    int green;

    red = color(c1 >> 16 &0xFF, c2 >> 16 &0xFF, per);
    green = color(c1 >> 8 &0xFF, c2 >> 8 &0xFF, per);
    blue = color(c1 &0xFF, c2 &0xFF, per);
    return ((red << 16) | (green << 8) | blue);
}

unsigned int  *gradiant_color(unsigned int color1, unsigned int color2, int nbr)
{
    unsigned int *colr;
    int i;
    int j;
    double per;
    
    colr = malloc(sizeof(unsigned int) * nbr);
    if (!colr)
        return (0);
    i = 1;
    j = 0;
    while(i <= nbr)
    {
        per = (double)i / (double)nbr;
        colr[j] = get_color(color1, color2, per);
        j++;
        i++;
    }
    return (colr);
}

void draw_complite(t_point p1, t_point p2, t_bren *s)
{
    if (p1.x < p2.x)
        s->sx = 1;
    else
        s->sx = -1;
    if (p1.y < p2.y)
        s->sy = 1;
    else
        s->sy = -1;
}

void brehensman_algo(t_point p1, t_point p2, t_fdf *data)
{
    int dx;
    int dy;
    int err;
    int e2;
    t_bren s;
    int j;
    unsigned int *color;
    
    j = 0;
    dx = abs((int)p2.x - (int)p1.x);
    dy = abs((int)p2.y - (int)p1.y);
    draw_complite(p1, p2, &s);
    err = (int)(dx - dy);
    if (dx > dy)
        color = gradiant_color(p1.color , p2.color, dx);
    else
        color = gradiant_color(p1.color , p2.color, dy);
    while (1)
    {
        my_mlx_put_pixels(data->img, (int)p1.x, (int)p1.y, color[j]);
        if ((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            p1.x += (int)s.sx;
        }
        if (e2 < dx)
        {
            err += dx;
            p1.y += (int)s.sy;
        }
        j++;
    }
    free(color);
}

t_point **ft_isometric_projection(t_map **matrix, t_fdf *data)
{
    int i = 0;
    int j = 0;
    t_point **matrix_2D;
    // double x;
    // double y;;
    double alpha = M_PI / 4;
    // double beta = M_PI / 4;
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
            matrix_2D[i][j].x = (matrix[i][j].x - matrix[i][j].y) * cos(alpha);
            matrix_2D[i][j].y = (matrix[i][j].x + matrix[i][j].y) / sqrt(2) * sin(alpha);
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
    // double tmp;
    //0.9252455
    //1.02009
    double alpha =  1.12252455;
    i = 0;
    while(i < data->map->lenght)
    {
        j = 0;
        while (j < data->map->with)
        {   
            matrix[i][j].x = matrix[i][j].x ;
            matrix[i][j].y = (matrix[i][j].y - matrix[i][j].z) * sin(alpha);
            matrix[i][j].z = matrix[i][j].z;
            matrix[i][j].color = matrix[i][j].color;
            j++;
        }
        i++;
    } 
    return (matrix);
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
    int j;

    i = 0;
    j = 0;
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
