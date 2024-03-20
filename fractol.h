/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:11:25 by bihixd            #+#    #+#             */
/*   Updated: 2024/03/20 05:07:05 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"

#define WIDTH  800
#define HEIGHT 750

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_d
{
	double x;
	double y;
}	t_d;
typedef struct f_fractol
{
    t_data  img;
	t_d		core;
    void    *mlx;
    void    *mlx_win;
    char	fractol_name;
	

    
}   t_fracol;

//MINILBX UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);




//LIBFT UTILS
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_tolower(int c);
int		ft_isdigit(int c);
double	ft_atod(const char *nptr);
#endif