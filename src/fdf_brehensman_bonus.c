/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brehensman_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:55:39 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:06 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	brehensman(t_point p1, t_point p2, t_fdf *data)
{
	if (p1.x < p2.x)
		data->brem.sx = 1;
	else
		data->brem.sx = -1;
	if (p1.y < p2.y)
		data->brem.sy = 1;
	else
		data->brem.sy = -1;
}

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

static void	brehensman_draw(t_fdf *data, t_point p1, t_point p2,
	unsigned int *color)
{
	int	j;

	j = 0;
	data->brem.err = (int)(data->brem.dx - data->brem.dy);
	while (1)
	{
		my_mlx_put_pixels(data->img, (int)p1.x, (int)p1.y, color[j]);
		if ((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y)
			break ;
		data->brem.e2 = 2 * data->brem.err;
		if (data->brem.e2 > -data->brem.dy)
		{
			data->brem.err -= data->brem.dy;
			p1.x += (int)data->brem.sx;
		}
		if (data->brem.e2 < data->brem.dx)
		{
			data->brem.err += data->brem.dx;
			p1.y += (int)data->brem.sy;
		}
		j++;
	}
}

void	brehensman_algo(t_point p1, t_point p2, t_fdf *data)
{
	unsigned int	*color;

	data->brem.dx = ft_abs((int)p2.x - (int)p1.x);
	data->brem.dy = ft_abs((int)p2.y - (int)p1.y);
	brehensman(p1, p2, data);
	if (data->brem.dx > data->brem.dy)
		color = gradiant_color(p1.color, p2.color, data->brem.dx);
	else
		color = gradiant_color(p1.color, p2.color, data->brem.dy);
	brehensman_draw(data, p1, p2, color);
	free(color);
}
