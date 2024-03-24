/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:55:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/24 07:28:21 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp  set_scil(int x, int y, t_fracol *fractol)
{
	t_comp tmp;

	tmp.r = ((x - WIDTH / 2) * (4.0 / WIDTH * fractol->zoom) + fractol->x);
	tmp.i = ((y - HEIGHT / 2) * (4.0 / HEIGHT * fractol->zoom) + fractol->y);
	return (tmp);
}

void draw_fractol(t_fracol *fractol)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{	
			fractol->c = set_scil(x, y, fractol);
			fractol->color = get_fractol(fractol);
			if (fractol->color == fractol->iter)
				my_mlx_pixel_put(&fractol->img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&fractol->img, x, y, ((fractol->color * 290)  << fractol->sheft_color));
			y++;
			if (fractol->sheft_color == 23)
				fractol->sheft_color = 1;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}


int main(int ac, char **av)
{
    t_fracol fractol;
	(void)av;
    if (ac > 1)
	{
		if (!ft_checkarg(&fractol, av, ac))
			list_available();
		ft_init_win(&fractol);
		ft_init_variable(&fractol);
		draw_fractol(&fractol);
		ft_hooks_fun(&fractol);
		mlx_loop(fractol.mlx);
	}
	list_available();
}

