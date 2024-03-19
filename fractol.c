/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihixd <bihixd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:55:52 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/18 21:54:06 by bihixd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_fracol *fractol;

    fractol = malloc(sizeof(t_fracol));

    fractol->mlx = mlx_init();
    fractol->mlx_win = mlx_new_window(fractol->mlx, HIGH, WITH, "fractol");
}