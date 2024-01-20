/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brehensman_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:55:39 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/19 18:56:32 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_complite(t_point p1, t_point p2, t_bren *s)
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
