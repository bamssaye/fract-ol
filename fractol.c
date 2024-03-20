/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:55:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/20 05:06:56 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//500x500
// void put_pxl(t_fracol *fractol)
// {
// 	// int i = 0;
// 	// int j = 0;
// 	// while (i <= WIDTH)
// 	// {	
// 	// 	j = i + 1;
// 	// 	while (j <= 1000)
// 	// 		my_mlx_pixel_put(&fractol->img, j++, i, 0x00FFFFFF);
// 	// 	i++;
// 	// }
// 	// i = 0;
// 	//  j = 0;
// 	// while (i <= WIDTH)
// 	// {	
// 	// 	j = i + 1;
// 	// 	while (j <= 500)
// 	// 		my_mlx_pixel_put(&fractol->img, i, j++, 0x00FFFFFF);
// 	// 	i++;
// 	// }

	
	
	
	
// }
int mandelbrot(double re, double im) {
    double Z_re = 0, Z_im = 0;
    for (int n = 0; n < 1000; ++n) {
        double Z_re2 = Z_re * Z_re, Z_im2 = Z_im * Z_im;
        if (Z_re2 + Z_im2 > 4) {
            return n; // Not in the Mandelbrot set
        }
        Z_im = 2 * Z_re * Z_im + im;
        Z_re = Z_re2 - Z_im2 + re;
    }
    return 1000; // In the Mandelbrot set
}

void draw_mandelbrot(t_fracol *fractol) {
    double minRe = -2.0;
    double maxRe = 1.0;
    double minIm = -1.2;
    double maxIm = minIm + (maxRe - minRe) * HEIGHT / WIDTH;
    double re_factor = (maxRe - minRe) / (WIDTH - 1);
    double im_factor = (maxIm - minIm) / (HEIGHT - 1);

    for (int y = 0; y < HEIGHT; ++y) {
        double c_im = maxIm - y * im_factor;
        for (int x = 0; x < WIDTH; ++x) {
            double c_re = minRe + x * re_factor;

            int iter = mandelbrot(c_re, c_im);
            int color = iter % 256;
            mlx_pixel_put(fractol->mlx, fractol->mlx_win, x, y, color * 0x0000CC00	);
        }
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, WIDTH, HEIGHT);

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
int ft_checkarg(t_fracol *fractol, char **av, int ac)
{
	int	i;

	i = -1;
	while (av[1][++i])
		av[1][i] = ft_tolower(av[1][i]);
	if (!ft_strcmp(av[1], "mandelbrot") && !av[2])
		fractol->fractol_name = 'm';
	else if (ac == 4){
		if (!ft_strcmp(av[1], "julia") && ft_atod(av[2]) && ft_atod(av[3]))
			fractol->fractol_name = 'j';
	}else
		return (0);
	fprintf(stderr ,"%c", fractol->fractol_name);
	return(1);
}
int main(int ac, char **av)
{
    t_fracol *fractol;
	(void)av;
    if (ac > 1)
	{
		fractol = malloc(sizeof(t_fracol));
		if (!ft_checkarg(fractol, av, ac))
			list_available();
    	fractol->mlx = mlx_init();
    	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
		fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
		fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length, &fractol->img.endian);
		
		// put_pxl(fractol);
		draw_mandelbrot(fractol);
		mlx_loop(fractol->mlx);
	}
	list_available();
}

