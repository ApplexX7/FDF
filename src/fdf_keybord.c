/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keybord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:32:26 by mohilali          #+#    #+#             */
/*   Updated: 2025/02/27 17:01:36 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FDF_Header.h"

void	ft_zooming(int key_press, t_fdf *env)
{
	if (key_press == ZOOM_IN_KEY)
		env->zoom += 1;
	if (key_press == ZOOM_OUT_KEY)
		env->zoom -= 1;
	if (key_press == COLOR_C_KEY)
		env->change_color += 1000;
	if (key_press == COLOR_V_KEY)
		env->change_color -=1000;
}

void	ft_translate(int key_press, t_fdf *env)
{
	if (key_press == RIGHT_KEY)
		env->translate.tran_x += 1;
	if (key_press == LEFT_KEY)
		env->translate.tran_x -= 1;
	if (key_press == DOWN_KEY)
		env->translate.tran_y += 1;
	if (key_press == UP_KEY)
		env->translate.tran_y -= 1;
}

void	color_rot(int key_press, t_fdf *env)
{
	if (key_press == RLY2_KEY)
	{
		env->change_color += 1000;
		env->fdf.y_rot += 0.01;
	}
	if (key_press == RRZ2_KEY)
	{
		env->change_color += 1000;
		env->fdf.z_rot -= 0.01;
	}
	if (key_press == RLZ2_KEY)
	{
		env->change_color += 1000;
		env->fdf.z_rot += 0.01;
	}
}

void	ft_color_rot(int key_press, t_fdf *env)
{
	if (key_press == RRX2_KEY)
	{
		env->change_color += 1000;
		env->fdf.x_rot += 0.01;
	}
	if (key_press == RLX2_KEY)
	{
		env->change_color += 1000;
		env->fdf.x_rot -= 0.01;
	}
	if (key_press == RRY2_KEY)
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
