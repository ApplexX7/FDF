/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:27:27 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/15 20:29:06 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <errno.h>


typedef struct s_img
{
    void *img;
	char	*addr;
	int  bpp;
	int line_len;
	int endian;
}  t_img;

typedef struct s_mlx
{
    int lenght;
    int withd;
    void *mlx_ptr;
    void *mlx_win;
    t_img img;
    int i;

} t_mlx;

void my_mlx_put_pixels(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *((unsigned int *) (offset + img->addr)) = color;
}



// void draw_circle(t_mlx *data, int centre_x, int centre_y, int radins, int color)
// {
//     int x = 0;
//     int  y = radins;
//     int d = 3 - 2 * radins;

//     while (x <= y)
//     {
//         my_mlx_put_pixels(&data->img, centre_x + x, centre_y + y, color);
//         my_mlx_put_pixels(&data->img, centre_x - x, centre_y + y, color);
//         my_mlx_put_pixels(&data->img, centre_x + x, centre_y - y, color);
//         my_mlx_put_pixels(&data->img, centre_x - x, centre_y - y, color);
//         my_mlx_put_pixels(&data->img, centre_x + x, centre_y + y, color);
//         my_mlx_put_pixels(&data->img, centre_x - x, centre_y + y, color);
//         my_mlx_put_pixels(&data->img, centre_x + x, centre_y - y, color);
//         my_mlx_put_pixels(&data->img, centre_x - x, centre_y - y, color);

//         if (d < 0)
//             d = d + 4 * x + 6;
//         else
//         {
//             d = d + 4 * (x - y) + 10;
//             y--;
//         }
//         x++;
//     }   
// }

// void draw_line(int x1, int y1, int x2, int y2) {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         if (x1 == x2 && y1 == y2) {
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

// void draw_line(int x1, int y1, int x2, int y2, t_mlx *data, int color) {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {

//         my_mlx_put_pixels(&data->img, x1, y1, color);
//         if (x1 == x2 && y1 == y2) {
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

// int draw(t_mlx *data) 
// {
//     int x = 0;
//     int y = 0;

//     while(y < 5)
//     {
//         x = 0;
//         while(x < 6)
//         {
//             draw_line(x, y, x + 50, y + 50, data, 0xffff);
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0);
//     return (0);
// }

// int main()
// {
//     t_mlx env;
//     env.i = 0;
//     env.lenght = 500;
//     env.withd = 500;
//     env.mlx_ptr = mlx_init();
//     env.mlx_win = mlx_new_window(env.mlx_ptr, env.withd, env.lenght, "test");
//     env.img.img = mlx_new_image(env.mlx_ptr, env.withd, env.lenght);
//     env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.line_len, &env.img.endian);
//     if (!env.img.addr)
//         exit(0);
//     mlx_loop_hook(env.mlx_ptr, draw, &env);
//     mlx_loop(env.mlx_ptr);
// }

void color_screen(t_mlx *data, int size ,int color)
{
    int x = (data->withd - size) / 2;
    int y = (data->lenght - size) / 2;
    int end_x = x + size;
    int end_y = y + size;
    int i = 0;
    
    draw_line(x, y , end_x, y, data, color);
    draw_line(end_x, y , end_x, end_y, data, color);
    draw_line(x, end_y , end_x, end_y, data, color);
    draw_line(x, y , x, end_y, data, color);

    // i = y + 1;
    // while (i < end_y)
    // {
    //     my_mlx_put_pixels(&data->img, end_x - 1, i, 0xff);
    //     i++;
    // }
    // i = x;
    // while (i < end_x)
    // {
    //     my_mlx_put_pixels(&data->img, i, end_y - 1, 0xff);
    //     i++;
    // }
    // i = y + 1;
    // while (i < end_y)
    // {
    //     my_mlx_put_pixels(&data->img, x, i, 0xff);
    //     i++;
    // }
}

void draw_lines(t_mlx *data) {

        color_screen(data, 300 , 0xfff);
}


int main() {
    t_mlx env;
    env.i = 0;
    env.lenght = 500;
    env.withd = 500;
    env.mlx_ptr = mlx_init();
    env.mlx_win = mlx_new_window(env.mlx_ptr, env.withd, env.lenght, "test");
    env.img.img = mlx_new_image(env.mlx_ptr, env.withd, env.lenght);
    env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.line_len, &env.img.endian);
    if (!env.img.addr)
        exit(0);

    draw_lines(&env);
    mlx_put_image_to_window(env.mlx_ptr, env.mlx_win, env.img.img, 0, 0);
    mlx_loop(env.mlx_ptr);

    return 0;
}