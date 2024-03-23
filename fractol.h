/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:11:25 by bihixd            #+#    #+#             */
/*   Updated: 2024/03/23 06:28:26 by bamssaye         ###   ########.fr       */
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
    t_data  	img;
	t_comp 		c;
	void    	*mlx;
    void    	*mlx_win;
	double		julia_i;
	double		julia_r;
    char		fractol_name;
	int 		color;
	int			iter;
	int 		sheft_color;
	double		zoom;
	double		x;
	double		y;
	
	
}   t_fracol;

//MINILBX UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void 	ft_init_win(t_fracol *fractol);
void 	ft_init_variable(t_fracol *fractol);
void 	ft_hooks_fun(t_fracol *fractol);
// check args
int 	ft_checkarg(t_fracol *fractol, char **av, int ac);
// get x and y 
t_comp  set_scil(int x, int y, t_fracol *fractol);//set init
//helper msg
void 	list_available();
// fractol set
int 	mandelbrot_set(t_fracol *fractol);
int 	juila_set(t_fracol *fractol);
int 	tricorn_set(t_fracol *fractol);
int 	get_fractol(t_fracol *fractol);
void 	draw_fractol(t_fracol *fractol);
//LIBFT UTILS
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
double	ft_atof(char *nptr);


#endif