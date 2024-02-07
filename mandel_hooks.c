/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:23:33 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/29 23:24:17 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	double	move_step;

	move_step = 0.3;
	if (keycode == 13)
		vars->center_imaginary -= move_step / vars->scale;
	else if (keycode == 1)
		vars->center_imaginary += move_step / vars->scale;
	else if (keycode == 0)
		vars->center_real -= move_step / vars->scale;
	else if (keycode == 2)
		vars->center_real += move_step / vars->scale;
	else if (keycode == 34)
		vars->gen_color += 10;
	else if (keycode == 32 && vars->gen_color > 10)
		vars->gen_color -= 10;
	else if (keycode == 7)
		vars->max_iter += 20;
	else if (keycode == 8 && vars->max_iter > 20)
		vars->max_iter -= 20;
	else if (keycode == 12)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	key_mouse(int button, int x, int y, t_vars *vars)
{
	double	zoom_factor;
	double	normalizedx;
	double	normalizedy;

	zoom_factor = 0.01;
	normalizedx = (2.0 * x / vars->width) - 1.0;
	normalizedy = 1.0 - (2.0 * y / vars->height);
	if (button == 4)
	{
		vars->scale *= 1.0 / (1.0 + zoom_factor);
		vars->move1 += normalizedy * (vars->move_step / vars->scale);
		vars->move -= normalizedx * (vars->move_step / vars->scale);
	}
	else if (button == 5)
	{
		vars->scale *= 1.0 + zoom_factor;
		vars->move1 += normalizedy * (vars->move_step / vars->scale);
		vars->move -= normalizedx * (vars->move_step / vars->scale);
	}
	return (0);
}

int	render_next_frame(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	draw_mandelbrot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
