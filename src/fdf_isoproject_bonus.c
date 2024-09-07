/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isoproject_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:09:29 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:47 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_put_pixels(t_img *img, int x, int y, int color)
{
	char	*offset;

	if ((0 < x && x < WIDTH) && (0 < y && y < LENGHT))
	{
		offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)(offset) = color;
	}
}

static t_point	**ft_malloc(t_point **matrix, t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->map->lenght)
	{
		matrix[i] = malloc(sizeof(t_point) * (data->map->with));
		if (!matrix)
			exit(0);
		i++;
	}
	return (matrix);
}

t_fdf	*copy_matrix(t_map **matrix, t_fdf *data)
{
	int		i;
	int		j;
	t_point	**matrix_2d;

	matrix_2d = malloc(sizeof(t_point *) * (data->map->lenght));
	if (!matrix_2d)
		exit(0);
	matrix_2d = ft_malloc(matrix_2d, data);
	i = -1;
	while (++i < data->map->lenght)
	{
		j = -1;
		while (++j < data->map->with)
		{
			matrix_2d[i][j].x = matrix[i][j].x;
			matrix_2d[i][j].y = matrix[i][j].y;
			if (matrix[i][j].z > 0)
				matrix_2d[i][j].z = (matrix[i][j].z + data->change_altitude);
			else
				matrix_2d[i][j].z = matrix[i][j].z;
			matrix_2d[i][j].color = matrix[i][j].color;
		}
	}
	data->mat = matrix_2d;
	return (data);
}

t_fdf	*ft_isometric_projection(t_fdf *data)
{
	int		i;
	int		j;
	double	x;
	double	alpha;
	double	beta;

	i = -1;
	alpha = M_PI / 4;
	beta = 0.615472907;
	while (++i < data->map->lenght)
	{
		j = -1;
		while (++j < data->map->with)
		{
			x = data->mat[i][j].x;
			data->mat[i][j].x = data->mat[i][j].x * cos(beta)
				- data->mat[i][j].y * sin(beta);
			data->mat[i][j].y = (data->mat[i][j].y * cos(alpha) + x * sin(alpha)
					- data->mat[i][j].z) / sqrt(2);
			data->mat[i][j].z = data->mat[i][j].z;
		}
	}
	return (data);
}
