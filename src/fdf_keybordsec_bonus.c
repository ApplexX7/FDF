/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keybordsec_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:54:21 by mohilali          #+#    #+#             */
/*   Updated: 2025/02/27 16:23:58 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_chang_altitude(int key_press, t_fdf *env)
{
	if (key_press == UP_W_KEY)
		env->change_altitude += 1;
	if (key_press == DOWN_S_KEY)
		env->change_altitude -= 1;
}

int	key_boom(int key_press, t_fdf *env)
{
	printf("%d\n", key_press);
	if (key_press == ZERO_KEY)
		ft_iniat_map(env);
	if (key_press == ESC_KEY)
		free_all(env);
	if (key_press == SPACE_KEY)
	{
		if (env->apple == 0)
			env->apple = 1;
		else
			env->apple = 0;
	}
	if (key_press == PRJ_KEY)
	{
		if (env->para == 0)
		{
			env->para = 1;
		}
		else
			env->para = 0;
	}
	else
		ft_state(key_press, env);
	env->key_pro = key_press;
	draw_projects(env, env->matrix);
	return (0);
}

void	ft_rotation_key(int key_press, t_fdf *env)
{

	if (key_press == RRX_KEY)
		env->fdf.x_rot += 0.01;
	if (key_press == RLX_KEY)
		env->fdf.x_rot -= 0.01;
	if (key_press == RRY_KEY)
		env->fdf.y_rot += 0.01;
	if (key_press == RLY_KEY)
		env->fdf.y_rot -= 0.01;
	if (key_press == RLZ_KEY)
		env->fdf.z_rot += 0.01;
	if (key_press == RRZ_KEY)
		env->fdf.z_rot -= 0.01;
}

int	loop_onit(t_fdf *env)
{
	if (env->apple == 1)
		ft_state(env->key_pro, env);
	draw_projects(env, env->matrix);
	return (0);
}

int	kill_win(t_fdf *env)
{
	free_all(env);
	return (0);
}
