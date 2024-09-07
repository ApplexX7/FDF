/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grad_color_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:52:50 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:32 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	color(int c1, int c2, double per)
{
	return (c1 + (c2 - c1) * per);
}

static unsigned int	get_color(int c1, int c2, double per)
{
	int	red;
	int	blue;
	int	green;

	red = color(c1 >> 16 & 0xFF, c2 >> 16 & 0xFF, per);
	green = color(c1 >> 8 & 0xFF, c2 >> 8 & 0xFF, per);
	blue = color(c1 & 0xFF, c2 & 0xFF, per);
	return ((red << 16) | (green << 8) | blue);
}

unsigned int	*gradiant_color(unsigned int color1, unsigned int color2,
	int nbr)
{
	unsigned int	*colr;
	int				i;
	int				j;
	double			per;

	colr = malloc(sizeof(unsigned int) * nbr);
	if (!colr)
		return (0);
	i = 1;
	j = 0;
	while (i <= nbr)
	{
		per = (double)i / (double)nbr;
		colr[j] = get_color(color1, color2, per);
		j++;
		i++;
	}
	return (colr);
}

t_fdf	*get_default_color(t_fdf *data)
{
	int	i;
	int	j;

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
