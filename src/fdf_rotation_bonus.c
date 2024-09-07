/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:58:44 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:23:30 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_fdf	*ft_xrotation(t_fdf *data)
{
	int		i;
	int		j;
	double	y;
	double	alpha;

	alpha = 0 + data->fdf.x_rot;
	i = 0;
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			y = data->mat[i][j].y;
			data->mat[i][j].x = data->mat[i][j].x;
			data->mat[i][j].y = data->mat[i][j].y * cos(alpha)
				- data->mat[i][j].z * sin(alpha);
			data->mat[i][j].z = data->mat[i][j].z * cos(alpha)
				+ y * sin(alpha);
			data->mat[i][j].color = data->mat[i][j].color;
			j++;
		}
		i++;
	}
	return (data);
}

t_fdf	*ft_yrotation(t_fdf *data)
{
	int		i;
	int		j;
	double	alpha;
	double	x;

	i = 0;
	alpha = 0 + data->fdf.y_rot;
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			x = data->mat[i][j].x;
			data->mat[i][j].x = data->mat[i][j].x * cos(alpha)
				+ data->mat[i][j].z * sin(alpha);
			data->mat[i][j].y = data->mat[i][j].y;
			data->mat[i][j].z = data->mat[i][j].z * cos(alpha) - x * sin(alpha);
			j++;
		}
		i++;
	}
	return (data);
}

t_fdf	*ft_zrotation(t_fdf *data)
{
	int		i;
	int		j;
	double	alpha;
	double	x;

	i = 0;
	if (data->para == 0)
		alpha = (-1.58 + data->fdf.z_rot);
	else
		alpha = 0 + data->fdf.z_rot;
	while (i < data->map->lenght)
	{
		j = 0;
		while (j < data->map->with)
		{
			x = data->mat[i][j].x;
			data->mat[i][j].x = data->mat[i][j].x * cos(alpha)
				- data->mat[i][j].y * sin(alpha);
			data->mat[i][j].y = data->mat[i][j].y * cos(alpha) + x * sin(alpha);
			data->mat[i][j].z = data->mat[i][j].z;
			j++;
		}
		i++;
	}
	return (data);
}
