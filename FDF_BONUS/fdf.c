/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:22 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 20:35:46 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int macro = 0;

void destroy_all(t_fdf *env)
{
    mlx_destroy_window(env->mlx_ptr, env->mlx_win);
    free(env->mlx_win);
    exit(0);
}

t_fdf *ft_init(char *av)
{
    t_fdf *env;
    t_img *img;
    char *titre;
    
    env = malloc(sizeof(t_fdf));
    img = malloc(sizeof(t_img));
    titre = ft_strjoin("FDF - ", av);
    if (!titre)
        exit(0);
    env->mlx_ptr = mlx_init();
    if (!env->mlx_ptr)
        free(titre), destroy_all(env);;
    env->mlx_win = mlx_new_window(env->mlx_ptr, WIDTH, LENGHT, titre);
    if (!env->mlx_win)
        free(titre), destroy_all(env);;
    free(titre);
    img->img = mlx_new_image(&env->mlx_ptr, WIDTH, LENGHT);
    if (!env->img->img)
        destroy_all(env);
    img->addr = mlx_get_data_addr(img->img, &img->bpp,&img->line_len, &img->endian);
    if (!env->img->addr)
        destroy_all(env);
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
void free_all(t_fdf *env)
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
void ft_state(int key_press, t_fdf *env)
{
    env->key_pro = key_press;
    if (key_press == 53)
        free_all(env);
    if (key_press == 83)
        env->fdf.x_rot += 0.01;
    if (key_press == 84)
        env->fdf.x_rot -= 0.01;
    if (key_press == 85)
        env->fdf.y_rot += 0.01;
    if (key_press == 86)
        env->fdf.y_rot -= 0.01;
    if (key_press == 87)
        env->fdf.z_rot += 0.01;
    if (key_press == 88)
        env->fdf.z_rot -= 0.01;
    if (key_press == 124)
        env->translate.tran_x += 1;
    if (key_press == 123)
        env->translate.tran_x -= 1;
    if (key_press == 125)
        env->translate.tran_y += 1;
    if (key_press == 126)
        env->translate.tran_y -= 1;
    if (key_press == 69)
        env->zoom += 1;
    if (key_press == 78)
        env->zoom -= 1;
    if (key_press== 82)
        ft_iniat_map(env);
    if (key_press == 8)
        env->change_color += 1000;
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
    if (key_press == 0)
        env->change_altitude += 1;
    if (key_press == 1)
        env->change_altitude -= 1;
    draw_projects(env, env->matrix);
    
}

int key_boom(int key_press, t_fdf *env)
{
    if (key_press == 49)
    {
        if (macro == 0)
            macro = 1;
        else
            macro = 0;
    }
    else
        ft_state(key_press, env);
    return 0;
}

void set_backgroud(t_fdf *env)
{
    int i;
    int j;

    i = 0;
    while (i < LENGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            my_mlx_put_pixels(env->img, j, i, 0);
            j++;
        }
        i++;
    }
}

t_fdf *ft_iniat_map(t_fdf *env)
{
    env->zoom = 0;
    env->change_altitude = 0;
    env->change_color = 0;
    env->fdf.x_rot = 0;
    env->fdf.y_rot = 0;
    env->fdf.z_rot = 0;
    env->translate.tran_x = 0;
    env->translate.tran_y = 0;
    return(env);
}

int loop_onit(t_fdf *env)
{
    if (macro == 1)
        ft_state(env->key_pro, env);
    return (0);
        
}

int main(int ac , char **av)
{
    t_fdf *env;
    
    if (ac == 2)
    {
        handling_name_file(av[1]);
        env = ft_init(av[1]);
        env = ft_iniat_map(env);
        atexit(ll);
        env->map = malloc(sizeof(t_map));
        env = handling_parsing(av[1], env);
        mlx_hook(env->mlx_win, 2, 0, key_boom, env);
        draw_projects(env, env->matrix);
        mlx_loop_hook(env->mlx_ptr, loop_onit, env);
        mlx_loop(env->mlx_ptr);
    }
    else
        write(2, "not enough argemants!!\n", 23);
    return 0;
}
