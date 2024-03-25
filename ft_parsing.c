/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:00:39 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/25 03:27:53 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	list_available(void)
{
	ft_putstr("\n\t#  The parameter is invalid. #\n");
	ft_putstr("\n* Prototype : >> ./fractol [FRACTOL NAME] \n");
	ft_putstr("\t\t- [FRACTOL NAME] : Julia, Mandelbrot, Tricorn\n");
	ft_putstr("\n* Multi-Julia: >> ./fractol Julia [1PA] [2PA]\n");
	ft_putstr("\t\t- [r] : Real Number \n\t\t- [i] : Imaginary Number  \n\n");
	exit(0);
}

int	get_fractol(t_fracol *fractol)
{
	if (fractol->fractol_name == 'm')
		return (mandelbrot_set(fractol));
	if (fractol->fractol_name == 'j')
		return (juila_set(fractol));
	if (fractol->fractol_name == 't')
		return (tricorn_set(fractol));
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_tolower_change(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	ft_checkarg(t_fracol *fractol, char **av, int ac)
{
	ft_tolower_change(av[1]);
	if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
		fractol->fractol_name = 'm';
	else if (!ft_strcmp(av[1], "julia") && ac <= 4)
	{
		if (ac == 4)
		{
			fractol->julia_r = ft_atof(av[2]);
			fractol->julia_i = ft_atof(av[3]);
		}
		else if (ac == 2)
		{
			fractol->julia_r = 0;
			fractol->julia_i = 0.8;
		}
		else
			return (0);
		fractol->fractol_name = 'j';
	}
	else if (ac == 2 && !ft_strcmp(av[1], "tricorn"))
		fractol->fractol_name = 't';
	else
		return (0);
	return (1);
}
