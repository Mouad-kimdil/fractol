/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:18:21 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/17 15:54:22 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	julia;
	t_vars		vars;

	if (ac != 2)
		return (ft_putendl_fd(ARGS_MSG, 2), 1);
	if (WIDTH <= 0 || WIDTH > 2560 || HEIGHT <= 0 || HEIGHT > 1440)
		my_exit(WRONG_RESOLUTION);
	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		mandelbrot_call(&vars);
	if (ft_strncmp(av[1], "julia", 6) == 0)
		julia_call(&julia);
	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
		my_fractal_call(&vars);
	else
		return (ft_putendl_fd(ARGS_MSG, 2), 1);
	return (0);
}
