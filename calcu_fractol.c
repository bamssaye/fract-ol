/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcu_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:59:17 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/23 06:42:01 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(t_fracol *fractol)
{
    t_comp z;
    t_comp t;
    
    int i = 0;
    z.i = 0;
    z.r = 0;
    while (z.r * z.r + z.i * z.i <= 4 && i < fractol->iter)
	{
        t.r = z.r * z.r - z.i * z.i + fractol->c.r;
        z.i = 2 * z.i * z.r + fractol->c.i;
        z.r = t.r;
        i++;
        
	}
	return (i);
}

int juila_set(t_fracol *fractol)
{
    t_comp t;
    t_comp z;
    int    i;
    
    i = 0;
    z = fractol->c;
    while (i < fractol->iter)
	{
        t.r = z.r * z.r - z.i * z.i + fractol->julia_r;
        t.i = 2 * z.r * z.i + fractol->julia_i;
        z = t;
        if (t.r * t.r + t.i * t.i >= 4)
            return (i);
        i++;
	}
	return (i);
   
}

int tricorn_set(t_fracol *fractol)
{
    t_comp t;
    t_comp z;
    int    i;
    
    i = 0;
    z = fractol->c;
    while (i < fractol->iter)
	{
        t.r = z.r * z.r - z.i * z.i + fractol->c.r;
        t.i = -2 * z.r * z.i + fractol->c.i;
        z = t;
        if (t.r * t.r + t.i * t.i >= 4)
            return (i);
        i++;
	}
	return (i);
}
