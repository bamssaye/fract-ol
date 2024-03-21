int mandelbrot(double re, double im) {

    t_comp z;

	z.i = 0;
	z.r = 0;
	int i = 0;
	while (i < 60) {
		
		double Z_re2 = z.r * z.r;
		double Z_im2 = z.i * z.i;
        
		if (Z_re2 + Z_im2 > 4)
            return i;
        z.i = 2 * z.r * z.i + im;
        z.r = Z_re2 - Z_im2 + re;
		
		i++;
    }
    return i; 
}

void draw_mandelbrot(t_fracol *fractol) {
    
	double minRe = -2.0 + fractol->sh_left ;
	double maxRe = 1.0 ;
	double minIm = -1.2 + fractol->sh_right;
	double maxIm = minIm + (maxRe - minRe) * HEIGHT / WIDTH;
	double re_factor = (maxRe - minRe) / (WIDTH - 1);
	double im_factor = (maxIm - minIm) / (HEIGHT - 1);
	
	for (int y = 0; y < HEIGHT; ++y) {
		double c_im = maxIm - y * im_factor;
		for (int x = 0; x < WIDTH; ++x) {
			double c_re = minRe + x * re_factor;
			int iter = mandelbrot(c_re, c_im);
			int color = iter % 256;
            mlx_pixel_put(fractol->mlx, fractol->mlx_win, x, y, (color * 190) << fractol->color);
        }
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, WIDTH + 20, HEIGHT + 20);

}
int	key_hook(int keycode, t_fracol *vars)
{
	if (keycode == 54)
		exit(0);
	if (keycode == 65307)
		vars->color++;
	fprintf(stderr,"%d\n", keycode);
	if (keycode == 65362)
		vars->sh_right++;
	if (keycode == 65364)
		vars->sh_left++;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	draw_mandelbrot(vars);
	//fprintf(stderr,"%d", vars->color);
	
	return (0);
}
