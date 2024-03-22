/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcu_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:59:17 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/22 13:31:06 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_set(t_fracol *fractol)
{
    double complex z = 0;
    int i = -1;
    while (cabs(z) <= 2 && ++i < fractol->iter)
        z = z*z + fractol->c;
    return i;
}

int juila_set(t_fracol *fractol)
{
    double complex z;
    z = fractol->c;
    int i = -1;
    while (cabs(z) <= 2 && ++i < fractol->iter)
        z = z*z + fractol->julia_r + fractol->julia_i * I;
    return (i);
}

