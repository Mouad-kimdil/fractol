/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:25:06 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/29 23:25:42 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_call(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "Mandelbrot");
	vars->img = mlx_new_image(vars->mlx, 800, 800);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->center_real = 0.0;
	vars->center_imaginary = 0.0;
	vars->scale = 1.0;
	vars->gen_color = 885;
	vars->max_iter = 60;
	vars->move = 2.0;
	vars->move1 = 2.0;
	vars->move_step = 0.09;
	vars->width = 800;
	vars->height = 800;
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 4, 0, key_mouse, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}
