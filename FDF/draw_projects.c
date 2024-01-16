/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:05:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/16 11:29:38 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_put_pixels(t_img *img, int x, int y, int color)
{
    char *offset;

    if ((0 < x && x < WIDTH) && (0 < y && y < LENGHT))
    {
        offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
        *(unsigned int *) (offset) = 0xFFFFFF;
        (void)color;
    }
}

// void brehensman_algo(int x1, int x2, int y1, int y2, t_fdf *data, int color) {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         // printf("x1 %d\n", x1);
//         // printf("y1 %d\n", y1);
//         // printf("data->mlx_ptr %p\n", data->mlx_ptr);
//         // printf("data->mlx_win %p\n", data->mlx_win);
//         // printf("x2 %d\n", x2);
//         // printf("y2 %d\n", y2);
//         // mlx_pixel_put(data->mlx_ptr, data->mlx_win,x1, y1, color);
//         my_mlx_put_pixels(data->img, x1, y1, color);
//         if (x1 == x2 && y1 == y2) {
//             printf("break\n");
//             break;
//         }
//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }


void plotLineHigh(int x0, int x1, int y0, int y1, t_fdf *data, int color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = (2 * dx) - dy;
    int x = x0;

    for (int y = y0; y <= y1; y++) {
        my_mlx_put_pixels(data->img,x0, y0, color);

        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2 * dx;
        }
    }
}

void draw_projects(t_fdf *data, t_map **matrix)
{
    int x;
    int y;
    y = 0;
    x = 0;
    // printf("data->map->lenght %d\n", data->map->lenght);
    // printf("data->map->with %d\n", data->map->with);
    while (y < data->map->lenght - 1)
    {
        x = 0;
        while (x < data->map->with - 1)
        {
            plotLineHigh(matrix[y][x].x , matrix[y][x + 1].x, matrix[y][x].y, matrix[y][x + 1].y, data,matrix[y][x].color);
            // brehensman_algo(matrix[y][x].x , matrix[y + 1][x].x, matrix[y][x].y, matrix[y + 1][x].y, data,matrix[y + 1][x].color);
            x++;
        }
        y++;
    }
}
