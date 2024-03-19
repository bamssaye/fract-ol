/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:11:25 by bihixd            #+#    #+#             */
/*   Updated: 2024/03/19 03:15:24 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "minilibx-linux/mlx.h"

#define WIDTH  500
#define HEIGHT 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct f_fractol
{
    t_data  img;
    void    *mlx;
    void    *mlx_win;
    





    
}   t_fracol;

//MINILBX UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);




//LIBFT UTILS
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
#endif