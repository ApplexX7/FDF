/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:22 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/19 17:15:43 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void destroy_all(t_fdf *env)
{
    mlx_destroy_window(env->mlx_ptr, env->mlx_win);
}

t_fdf *ft_init(char *av)
{
    t_fdf *env;
    t_img *img;
    char *titre;
    
    env = malloc(sizeof(t_fdf));
    img= malloc(sizeof(t_img));
    titre = ft_strjoin("FDF - ", av);
    if (!titre)
        exit(0);
    env->mlx_ptr = mlx_init();
    if (!env->mlx_ptr)
        free(titre), exit(0);
    env->mlx_win = mlx_new_window(env->mlx_ptr, WIDTH, LENGHT, titre);
    if (!env->mlx_win)
        free(titre), exit(0);
    free(titre);
    img->img = mlx_new_image(&env->mlx_ptr, WIDTH, LENGHT);
    if (!env->img->img)
        exit(0);
    img->addr = mlx_get_data_addr(img->img, &img->bpp,&img->line_len, &img->endian);
    if (!env->img->addr)
        exit(0);
    env->img = img;
    return (env);
}

void handling_name_file(char *av)
{
    int fd;
    int len;

    len = ft_strlen(av);
    if (ft_strncmp(av + (len - 4), ".fdf", 4) != 0)
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
        perror(strerror(errno)), exit (0);
}
void ll()
{
    system("leaks fdf");
}

int key_press(int key_press, t_fdf *env)
{
    (void)env;
    if (key_press == 53)
    {
        mlx_destroy_image(env->mlx_ptr, env->img->img);
        mlx_destroy_window(env->mlx_ptr, env->mlx_win);
        free(env->mlx_ptr);
        free(env);
        env->mlx_ptr = NULL;
        exit(0);
    }
    return 0;
}
int main(int ac , char **av)
{
    t_fdf *env;
    t_map **matrix;
    
    if (ac == 2)
    {
        handling_name_file(av[1]);
        env = ft_init(av[1]);
        atexit(ll);
        env->map = malloc(sizeof(t_map));
        matrix = handling_parsing(av[1], env);
        draw_projects(env, matrix);
        mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->img->img, 0, 0);
        mlx_key_hook(env->mlx_win, key_press, env);
        mlx_loop(env->mlx_ptr);
    }
    else
        write(2, "not enough argemants!!\n", 23);
    return 0;
}
