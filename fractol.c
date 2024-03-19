/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:55:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/19 03:52:04 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pxl(t_fracol *fractol)
{
	int i = WIDTH / 2;
	int j = 0;
	while (i < WIDTH)
	{
		my_mlx_pixel_put(&fractol->img, i, i, 0x00FF0000);
		my_mlx_pixel_put(&fractol->img, j, j, 0x00FF0000);
		i++;
		j++;
	}
	
	
}
void list_available()
{
	ft_putstr("\n\t#  The parameter is invalid. #\n");
	ft_putstr("\n* Prototype : >> ./fractol [FRACTOL NAME] \n");
	ft_putstr("\t\t- [FRACTOL NAME] : Julia, Mandelbrot\n");
	ft_putstr("\n* Multi-Julia: >> ./fractol Julia [1PA] [2PA]\n");
	ft_putstr("\t\t- [1PA] : First paramter \n\t\t- [2PA] : Second paramter  \n\n");
	exit(0);
}

int main(int ac, char **av)
{
    t_fracol *fractol;
	(void)av;
    if (ac == 3)
	{
		if (ft_strcmp(av[1], "Julia") || ft_strcmp(av[1], "Mandelbrot"))
			list_available();
		fractol = malloc(sizeof(t_fracol));
    	fractol->mlx = mlx_init();
    	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
		fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
		fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length, &fractol->img.endian);
		
		put_pxl(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
		mlx_loop(fractol->mlx);
	}
	list_available();
}

