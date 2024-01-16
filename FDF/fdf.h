/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:32:14 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/16 10:52:59 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define WIDTH 1920
#define LENGHT 1080
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

typedef struct s_fdf
{
	void *mlx_ptr;
	void *mlx_win;
	t_img *img;
	t_map *map;
	t_map **matrix;
		
} t_fdf;

// typedef struct s_size
// {
// 	int x;
// 	int y;
// 	int z;
// 	int x_pixel;
// 	int y_pixel;
// 	double alpha;
// }	t_size;

/*heleper functions*/
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(const char *s);
t_map	**handling_parsing(char *av, t_fdf *env);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
unsigned int atoi_base(const char *s, const char *base);
void draw_projects(t_fdf *data, t_map **matrix);

#endif