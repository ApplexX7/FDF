/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keybord_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:32:26 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:22:56 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_zooming(int key_press, t_fdf *env)
{
	if (key_press == 34)
		env->zoom += 1;
	if (key_press == 31)
		env->zoom -= 1;
	if (key_press == 8)
		env->change_color += 1000;
}

void	ft_translate(int key_press, t_fdf *env)
{
	if (key_press == 124)
		env->translate.tran_x += 1;
	if (key_press == 123)
		env->translate.tran_x -= 1;
	if (key_press == 125)
		env->translate.tran_y += 1;
	if (key_press == 126)
		env->translate.tran_y -= 1;
}

void	color_rot(int key_press, t_fdf *env)
{
	if (key_press == 11)
	{
		env->change_color += 1000;
		env->fdf.y_rot += 0.01;
	}
	if (key_press == 45)
	{
		env->change_color += 1000;
		env->fdf.z_rot -= 0.01;
	}
	if (key_press == 46)
	{
		env->change_color += 1000;
		env->fdf.z_rot += 0.01;
	}
}

void	ft_color_rot(int key_press, t_fdf *env)
{
	if (key_press == 9)
	{
		env->change_color += 1000;
		env->fdf.x_rot += 0.01;
	}
	if (key_press == 6)
	{
		env->change_color += 1000;
		env->fdf.x_rot -= 0.01;
	}
	if (key_press == 7)
	{
		env->change_color += 1000;
		env->fdf.y_rot -= 0.01;
	}
	color_rot(key_press, env);
}

void	ft_state(int key_press, t_fdf *env)
{
	ft_rotation_key(key_press, env);
	ft_zooming(key_press, env);
	ft_translate(key_press, env);
	ft_color_rot(key_press, env);
	ft_chang_altitude(key_press, env);
}
