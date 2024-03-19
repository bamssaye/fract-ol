/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:05:21 by bamssaye          #+#    #+#             */
/*   Updated: 2024/03/19 07:17:50 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
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

double	ft_atod(const char *nptr)
{
	int	i;
	int	p;
	double	n;
	double  j;

	i = 0;
	j = 0;
	p = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
	    i++;
	if (nptr[i] == '-')
		p *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
		n = 10 * n + nptr[i++] - 48;
	if (nptr[i] != '.' && nptr[i])
	    return (0);
	while (ft_isdigit(nptr[++i]))
	    j = 10 * j + nptr[i] - 48;
	if(j)
	    j /= pow(10, (int)log10(j) + 1);
	n += j;
	return (n * p);
}
