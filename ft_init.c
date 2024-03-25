/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:16:36 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/25 03:27:21 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_win(t_fracol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length, &fractol->img.endian);
}

void	ft_init_variable(t_fracol *fractol)
{
	fractol->color = 1;
	fractol->iter = 100;
	fractol->zoom = 1;
	fractol->x = 0;
	fractol->y = 0;
	fractol->sheft_color = 0x00080000;
}
