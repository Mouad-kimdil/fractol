/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fractal_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 00:34:04 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/16 14:53:39 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burn_key_hook(int keycode, t_vars *vars)
{
	double	move_step;

	move_step = 0.3;
	if (keycode == UP)
		vars->center_imaginary -= move_step / vars->scale;
	else if (keycode == DOWN)
		vars->center_imaginary += move_step / vars->scale;
	else if (keycode == LEFT)
		vars->center_real -= move_step / vars->scale;
	else if (keycode == RIGHT)
		vars->center_real += move_step / vars->scale;
	else if (keycode == COLOR_UP)
		vars->gen_color += 10;
	else if (keycode == COLOR_DOWN && vars->gen_color > 10)
		vars->gen_color -= 10;
	else if (keycode == ITER_UP)
		vars->max_iter += 5;
	else if (keycode == ITER_DOWN && vars->max_iter > 20)
		vars->max_iter -= 5;
	else if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	burn_key_mouse(int button, int x, int y, t_vars *vars)
{
	double	zoom_factor;
	double	normalizedx;
	double	normalizedy;

	zoom_factor = 0.03;
	normalizedx = (2.0 * x / WIDTH) - 1.0;
	normalizedy = 1.0 - (2.0 * y / HEIGHT);
	if (button == ZOOM_OUT)
	{
		vars->scale *= 1.0 / (1.0 + zoom_factor);
		vars->move1 += normalizedy * (vars->move_step / vars->scale);
		vars->move -= normalizedx * (vars->move_step / vars->scale);
		vars->center_real += normalizedx * (vars->move_step / vars->scale);
		vars->center_imaginary -= normalizedy * (vars->move_step / vars->scale);
	}
	else if (button == ZOOM_IN)
	{
		vars->scale *= 1.0 + zoom_factor;
		vars->move1 += normalizedy * (vars->move_step / vars->scale);
		vars->move -= normalizedx * (vars->move_step / vars->scale);
		vars->center_real += normalizedx * (vars->move_step / vars->scale);
		vars->center_imaginary -= normalizedy * (vars->move_step / vars->scale);
	}
	return (0);
}
