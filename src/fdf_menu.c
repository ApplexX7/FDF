/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:31:13 by mohilali          #+#    #+#             */
/*   Updated: 2025/02/28 11:09:50 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FDF_Header.h"

static void	for_extra_keys(void *mlx, void *win, int y)
{
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF, "RGB press : C & V");
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF,
		"Magic things press Space and then:");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 1");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 2");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 3");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 4");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 5");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Press : Numpad 6");
}

void	print_menu(t_fdf *env)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = env->mlx_ptr;
	win = env->mlx_win;
	mlx_string_put(mlx, win, 50, y += 20, 0xFFFFFF, "//// CONTROL INFO ////");
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF, "Zom In/Out :");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "Press key => I and O");
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF, "Rotation :");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "X - axis => 1/2");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "Y - axis => 3/4");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "Z - axis => 5/6");
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF, "Translate :");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "Move Up and Down : ^ / v");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF,
		"Move left and Right : < / >");
	mlx_string_put(mlx, win, 15, y += 40, 0xFFFFFF, "Parallel projection : P");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Changing Altitude :");
	mlx_string_put(mlx, win, 30, y += 30, 0xFFFFFF, "Press keys => W / S");
	mlx_string_put(mlx, win, 15, y += 30, 0xFFFFFF, "Back to Zero Press : 0");
	for_extra_keys(mlx, win, y);
}
