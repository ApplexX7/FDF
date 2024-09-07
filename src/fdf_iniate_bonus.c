/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iniate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:36:45 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:40 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_fdf	*ft_iniat_map(t_fdf *env)
{
	env->zoom = 0;
	env->para = 0;
	env->apple = 0;
	env->change_altitude = 0;
	env->change_color = 0;
	env->fdf.x_rot = 0;
	env->fdf.y_rot = 0;
	env->fdf.z_rot = 0;
	env->translate.tran_x = 0;
	env->translate.tran_y = 0;
	return (env);
}

void	set_backgroud(t_fdf *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < LENGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < 100 * 30 && j < 300)
				my_mlx_put_pixels(env->img, j, i, 0x202020);
			else
				my_mlx_put_pixels(env->img, j, i, 0);
			j++;
		}
		i++;
	}
}

void	destroy_all(t_fdf *env)
{
	mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	free(env->mlx_win);
	exit(0);
}

t_fdf	*ft_init(t_fdf *env)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		(free(env), exit(0));
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		destroy_all(env);
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIDTH, LENGHT,
			"Fil de Fer");
	if (!env->mlx_win)
		destroy_all(env);
	img->img = mlx_new_image(&env->mlx_ptr, WIDTH, LENGHT);
	if (!env->img->img)
		destroy_all(env);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!env->img->addr)
		destroy_all(env);
	env->img = img;
	return (env);
}

void	free_all(t_fdf *env)
{
	destroy_matrix(env->matrix, env);
	mlx_destroy_image(env->mlx_ptr, env->img->img);
	mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	free(env->img);
	free(env->map);
	free(env);
	env->mlx_ptr = NULL;
	exit(0);
}
