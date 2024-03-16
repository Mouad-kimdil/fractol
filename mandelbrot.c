/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:25:06 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/16 21:39:22 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_mandelbrot(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		my_exit(INIT_FAILED);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (!vars->win)
		my_exit(NEW_WIN_FAILED);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		my_exit(NEW_IMG_FAILED);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!vars->addr)
		my_exit(GET_DATA_ADDR_FAILED);
	vars->center_real = 0.0;
	vars->center_imaginary = 0.0;
	vars->scale = 1.0;
	vars->gen_color = 5;
	vars->max_iter = 10;
	vars->move = 2.0;
	vars->move1 = 2.0;
	vars->move_step = 0.09;
}

void	mandelbrot_call(t_vars *vars)
{
	initialize_mandelbrot(vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 4, 0, key_mouse, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}
