/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:22 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 11:17:25 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	handling_name_file(char *av)
{
	int	fd;
	int	len;

	len = ft_strlen(av);
	if (ft_strncmp(av + (len - 4), ".fdf", 4) != 0 || len == 4)
	{
		write(2, "Error: Invalid file!\n", 21);
		exit(0);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: file not found!\n", 23);
		exit(0);
	}
	if (close(fd) == -1)
		(perror(strerror(errno)), exit (0));
}

int	main(int ac, char **av)
{
	t_fdf	*env;

	if (ac == 2)
	{
		env = malloc(sizeof(t_fdf));
		if (!env)
			exit(0);
		handling_name_file(av[1]);
		env = ft_init(env);
		env = ft_iniat_map(env);
		env->map = malloc(sizeof(t_map));
		env = handling_parsing(av[1], env);
		mlx_hook(env->mlx_win, 2, 0, key_boom, env);
		mlx_hook(env->mlx_win, 17, 0, kill_win, env);
		draw_projects(env, env->matrix);
		mlx_loop_hook(env->mlx_ptr, loop_onit, env);
		mlx_loop(env->mlx_ptr);
	}
	else
		write(2, "not enough argemants!!\n", 23);
	return (0);
}
