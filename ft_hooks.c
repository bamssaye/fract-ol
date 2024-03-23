/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:01:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/23 07:01:55 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_clear_all(t_fracol *fractol)
{
    //
    // mlx_destroy_image(fractol->mlx, fractol->img.img);
    // mlx_destroy_display(fractol->mlx);
    // mlx_destroy_window(fractol->mlx, fractol->mlx_win);
    exit(0);
    return (0);
}
int	key_hook(int keycode, t_fracol *fractol)
{
	fprintf(stderr, "%d", keycode);
	
	if (keycode == 65307)
		ft_clear_all(fractol);
	if (keycode == 65363)
		fractol->x -= 0.1 * fractol->zoom;
	if (keycode == 65361)
		fractol->x += 0.1 *fractol->zoom;
	if (keycode == 65362)
		fractol->y += 0.1 * fractol->zoom;
    if (keycode == 65364)
		fractol->y -= 0.1 * fractol->zoom;
    if (keycode == 65451)
        fractol->sheft_color++;
	draw_fractol(fractol);
	return (0);
}
int mouse_hook(int keycode, int x, int y, t_fracol *fractol)
{
    fprintf(stderr, "%d x %d y %d \n", keycode , x , y);
    double complex old;
    double complex new;
    
    // old = fractol->c;
    // if (keycode == 4)
    // {
    //     fractol->zoom *= 1.1;
    //   //  new = set_scil(x, y, fractol);
    //     fractol->x = new - old;
    // }
    // if (keycode == 5)
    // {
    //         fractol->zoom += 0.1;
    //         fractol->zoom *= 1.1;
    //       //  new = set_scil(x, y, fractol);
    //         fractol->y = new - old;
    // }

    //draw_fractol(fractol);
    return (0);
}
void ft_hooks_fun(t_fracol *fractol)
{
    mlx_key_hook((*fractol).mlx_win, key_hook, fractol);
    mlx_hook((*fractol).mlx_win, 17 , 0, ft_clear_all, fractol);
    mlx_mouse_hook((*fractol).mlx_win, mouse_hook, fractol);
}