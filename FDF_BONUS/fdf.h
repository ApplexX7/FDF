/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:32:14 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/20 20:43:42 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define WIDTH 1024
#define LENGHT 1024
#define BUFFER_SIZE 500

#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <errno.h>

typedef struct s_bren
{
	int sx;
	int sy;
} t_bren;

typedef struct  s_img
{
	void *img;
	char	*addr;
	int  bpp;
	int line_len;
	int endian;
} t_img;

typedef struct s_map
{
	int with;
	int lenght;
	double x;
	double y;
	double z;
	unsigned int color;
}	t_map;

typedef struct s_point
{
	double x;
	double y;
	double z;
	unsigned int color;
}	t_point;

typedef struct control
{
	double x_rot;
	double y_rot;
	double z_rot;
} t_con;

typedef struct s_trans
{
	double tran_x;
	double tran_y;
} t_tran;

typedef struct s_fdf
{
	void *mlx_ptr;
	void *mlx_win;
	t_img *img;
	t_map *map;
	t_map **matrix;
	t_point **mat;
	double Z_max;
	t_tran translate;
	unsigned int change_color;
	int change_altitude;
	int zoom;
	int scal;
	t_con fdf;
	int key_pro;
		
} t_fdf;


/*heleper functions*/
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(const char *s);
t_fdf *handling_parsing(char *av, t_fdf *env);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
unsigned int atoi_base(const char *s, const char *base);
void draw_projects(t_fdf *data, t_map **matrix);
t_map **get_coordonnes(char *av, t_fdf *data);
void ft_free(char **arr);
/*draw map*/
t_fdf *ft_iniat_map(t_fdf *env);
unsigned int  *gradiant_color(unsigned int color1, unsigned int color2, int nbr);
void brehensman_algo(t_point p1, t_point p2, t_fdf *data);
t_fdf *ft_isometric_projection(t_fdf *data);
t_fdf *ft_xrotation(t_fdf *data);
void my_mlx_put_pixels(t_img *img, int x, int y, int color);
t_fdf *ft_zrotation(t_fdf *data);
t_fdf *ft_yrotation(t_fdf *data);
t_fdf *ft_xrotation(t_fdf *data);
void set_backgroud(t_fdf *env);
t_fdf *copy_matrix(t_map **matrix, t_fdf *data);
void destroy_matrix(t_map **matrix, t_fdf *data);
void free_matrix(t_point **matrix, t_fdf *data);

#endif