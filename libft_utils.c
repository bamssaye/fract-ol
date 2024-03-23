/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:05:21 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/23 06:40:17 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

static void err(char *str, int i, int c)
{
    if (c == 1 && !ft_isdigit(str[i]))
        list_available();
    if (c == 2 && str[i] != '.'&& str[i])
        list_available();
    if (c == 3 && str[i] != '\0')
        list_available();
}

double	ft_atof(char *nptr)
{
    double v, p;
    int i, sign;
    
    i = 0;
    sign = 1;
    v = 0;
    p = 1.0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
        i++;
    if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
    err(nptr, i, 1);
    while(ft_isdigit(nptr[i]))
        v = 10 * v + nptr[i++] - '0';
     err(nptr, i, 2);
    if (nptr[i] == '.' && nptr[i + 1] != '\0')
        i++;
    while (ft_isdigit(nptr[i])){
        v = 10.0 * v + (nptr[i++] - '0');
        p *= 10;
    }
     err(nptr, i, 3);
    return sign * v / p;
}
