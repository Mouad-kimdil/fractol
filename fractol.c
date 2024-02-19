/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:18:21 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/19 04:24:34 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int len)
{
	int  i;

	i = 0;
	while ((s1[i] || s2[i]) && i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_fractal	julia;
	t_vars		vars;

    if (ac != 2)
        return (0);
	if (WIDTH <= 0 || WIDTH >= 1500 || HEIGHT <= 0 || HEIGHT >= 1500)
		return (0);
    if (ft_strncmp(av[1], "julia", 6) == 0)
		julia_call(&julia);
	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		mandelbrot_call(&vars);
	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
		my_fractal_call(&vars);
	return (0);
}