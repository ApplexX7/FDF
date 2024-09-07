/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:05:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:23 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	destroy_matrix(t_map **matrix, t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->map->lenght)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_matrix(t_point **matrix, t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->map->lenght)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_prepar_coordonnees(t_fdf *data)
{
	data = get_default_color(data);
	data = ft_xrotation(data);
	data = ft_yrotation(data);
	data = ft_zrotation(data);
}

void	ft_iso_part(t_fdf *data)
{
	ft_iniate_centre(data);
	ft_prepar_coordonnees(data);
	if (data->para == 0)
		data = ft_isometric_projection(data);
}

void	draw_projects(t_fdf *data, t_map **matrix_3D)
{
	data->i = -1;
	set_backgroud(data);
	data = copy_matrix(matrix_3D, data);
	ft_iso_part(data);
	complite_centre(data);
	while (++data->i < data->map->lenght - 1)
	{
		data->j = -1;
		while (++data->j < data->map->with - 1)
		{
			brehensman_algo(data->mat[data->i][data->j],
				data->mat[data->i][data->j + 1], data);
			brehensman_algo(data->mat[data->i][data->j],
				data->mat[data->i + 1][data->j], data);
			brehensman_algo(data->mat[data->i + 1][data->j],
				data->mat[data->i + 1][data->j + 1], data);
			brehensman_algo(data->mat[data->i][data->j + 1],
				data->mat[data->i + 1][data->j + 1], data);
		}
	}
	free_matrix(data->mat, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	print_menu(data);
}
