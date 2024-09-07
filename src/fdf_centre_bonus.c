/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_centre_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:46:56 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:14 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	get_zmax(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	data->z_max = data->mat[0][0].z;
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			if (data->mat[i][j].z > data->z_max)
				data->z_max = data->mat[i][j].z;
			j++;
		}
		i++;
	}
}

static void	ft_scale(t_fdf *data)
{
	if (data->zoom > 0)
		data->scal = round(fmax(fmin((WIDTH - 300) / data->map->with / 2,
						LENGHT / data->map->lenght / 2), 1)) + data->zoom;
	else
	{
		data->scal = round(fmax(fmin((WIDTH - 300) / data->map->with / 2,
						LENGHT / data->map->lenght / 2), 1));
		data->zoom = 0;
	}
}

void	ft_iniate_centre(t_fdf *data)
{
	int		i;
	int		j;
	double	square_x;
	double	square_y;

	ft_scale(data);
	i = 0;
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			square_x = (data->map->with * data->scal) / 2;
			square_y = (data->map->lenght * data->scal) / 2;
			data->mat[i][j].x = round(data->mat[i][j].x * data->scal
					- square_x);
			data->mat[i][j].y = round(data->mat[i][j].y * data->scal
					- square_y);
			data->mat[i][j].z = round(data->mat[i][j].z * data->scal);
			j++;
		}
		i++;
	}
}

void	complite_centre(t_fdf *data)
{
	int		j;
	int		i;
	double	square_x;
	double	square_y;

	i = 0;
	get_zmax(data);
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			square_x = (WIDTH / 2) + (data->translate.tran_x * data->scal);
			square_y = ((LENGHT + data->z_max / 2) / 2)
				+ (data->translate.tran_y * data->scal);
			data->mat[i][j].x = round(data->mat[i][j].x + square_x);
			data->mat[i][j].y = round(data->mat[i][j].y + square_y);
			data->mat[i][j].z = round(data->mat[i][j].z);
			j++;
		}
		i++;
	}
}
