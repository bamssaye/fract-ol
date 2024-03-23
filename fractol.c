/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:55:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/23 07:07:59 by bamssaye         ###   ########.fr       */
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
int	gen_color(int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / 60;
	if (iteration >= 60)
		return (0);
	// r = (int)(sin(2 * 3.14 * t) * 127 + 128);
	// g = (int)(sin(2 * 3.14 * t + 2) * 127 + 128);
	// b = (int)(sin(2 * 3.14 * t + 4) * 127 + 128);
	//return (r << 16 | g << 8 | b);
// 	int	create_trgb(int t, int r, int g, int b)
// {
	//0x 00 00 00 00
	
	return (t << 24 | r << 16 | g << 8 | b);
}

void draw_fractol(t_fracol *fractol)
{
	int x;
	int y;
	
	x = 0;
	fprintf(stderr, "dsds %f %c\n", fractol->y, fractol->fractol_name);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{	
			fractol->c = set_scil(x, y, fractol);
			fractol->color = gen_color(get_fractol(fractol));
			// if (fractol->color == fractol->iter)
			// 	my_mlx_pixel_put(&fractol->img, x, y, 0x00000000);
			// else
				my_mlx_pixel_put(&fractol->img, x, y, fractol->color << fractol->sheft_color);
			y++;
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

