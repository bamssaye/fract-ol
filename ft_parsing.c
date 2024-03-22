/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:00:39 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/22 13:30:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (!ft_strcmp(av[1], "mandelbrot"))
		fractol->fractol_name = 'm';
	
	if (!ft_strcmp(av[1], "julia") && ac <= 4)
	{
		
		if (ac == 4 && ft_atod(av[2]) && ft_atod(av[3]))
		{
			fractol->julia_r = ft_atod(av[2]);
			fractol->julia_i = ft_atod(av[3]);
		}
		else
		{
			fractol->julia_r = 0;
			fractol->julia_i = 0.8;
		}
		fractol->fractol_name = 'j';	
	}
	//else
	// 	return (0);
	return(1);
}
