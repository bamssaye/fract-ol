/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:11:25 by bihixd            #+#    #+#             */
/*   Updated: 2024/03/22 12:53:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <complex.h>
#include "minilibx-linux/mlx.h"

#define WIDTH  800
#define HEIGHT 750
#define MAX_ITER 60
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_d
{
	double i;
	double r;
}	t_comp;

typedef struct f_fractol
{
    t_data  img;
	double		julia_i;
	double		julia_r;
    void    *mlx;
    void    *mlx_win;
    char	fractol_name;
	int 	color;
	int		iter;
	int 	sheft_color;
	double		zoom;
	double		x;
	double		y;
	double complex c;
}   t_fracol;

//MINILBX UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int ft_checkarg(t_fracol *fractol, char **av, int ac);
void list_available();
void ft_hooks_fun(t_fracol *fractol);
void draw_fractol(t_fracol *fractol);
double complex set_scil(int x, int y, t_fracol *fractol);
//set init
void ft_init_win(t_fracol *fractol);
void ft_init_variable(t_fracol *fractol);
int mandelbrot_set(t_fracol *fractol);
int juila_set(t_fracol *fractol);
//LIBFT UTILS
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_tolower(int c);
int		ft_isdigit(int c);
double	ft_atod(const char *nptr);
#endif