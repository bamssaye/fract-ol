/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:01:30 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/25 02:24:45 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_clear_all(t_fracol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img);
    mlx_destroy_window(fractol->mlx, fractol->mlx_win);
    mlx_destroy_display(fractol->mlx);
    free(fractol->mlx);
    exit(0);
    return (0);
}

void get_color_all(t_fracol *fractol, int keycode)
{
    if (keycode == 112)
        fractol->sheft_color = 0xa33db5;
    if (keycode == 111)
        fractol->sheft_color = 0xcb94e0;
    if (keycode == 105)
        fractol->sheft_color = 0x5b0c91;
    if (keycode == 117)
        fractol->sheft_color = 0xe25edf;
    if (keycode == 121)
        fractol->sheft_color = 0xfc9725;
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
    get_color_all(fractol, keycode);
    mlx_clear_window(fractol->mlx, fractol->mlx_win);
	draw_fractol(fractol);
	return (0);
}
int mouse_hook(int keycode, int x, int y, t_fracol *fractol)
{
    t_comp old;
    t_comp new;
     
    old = set_scil(x ,y, fractol);
    if (keycode == 4)
    {
        fractol->zoom *= 1.2;
        new = set_scil(x ,y, fractol);
        fractol->x += old.r - new.r;
        fractol->y += old.i - old.i;
    }
    if (keycode == 5)
    {
            fractol->zoom *= 0.7;
            new = set_scil(x ,y, fractol);
            fractol->x += old.r - new.r;
            fractol->y += old.i - old.i;
    }
    mlx_clear_window(fractol->mlx, fractol->mlx_win);
    draw_fractol(fractol);
    return (0);
}

void ft_hooks_fun(t_fracol *fractol)
{
    mlx_key_hook((*fractol).mlx_win, key_hook, fractol);
    mlx_hook((*fractol).mlx_win, 17 , 0, ft_clear_all, fractol);
    mlx_mouse_hook((*fractol).mlx_win, mouse_hook, fractol);
}