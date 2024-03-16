/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:38:51 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/16 15:05:17 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *param)
{
	t_fractal	*julia;

	julia = (t_fractal *)param;
	mlx_destroy_window(julia->mlx, julia->win);
	my_exit("window closed");
	return (0);
}

int	key_hook_julia(int keycode, t_fractal *julia)
{
	if (keycode == RIGHT)
		julia->move -= julia->move_step;
	else if (keycode == LEFT)
		julia->move += julia->move_step;
	else if (keycode == UP)
		julia->move1 -= julia->move_step1;
	else if (keycode == DOWN)
		julia->move1 += julia->move_step1;
	if (keycode == COLOR_UP)
		julia->gen_color += 10;
	else if (keycode == COLOR_DOWN && julia->gen_color > 10)
		julia->gen_color -= 10;
	else if (keycode == ITER_UP)
		julia->max_iter += 5;
	else if (keycode == ITER_DOWN && julia->max_iter > 20)
		julia->max_iter -= 5;
	else if (keycode == ESC)
	{
		mlx_destroy_window(julia->mlx, julia->win);
		exit(0);
	}
	return (0);
}

int	key_mouse_julia(int button, int x, int y, t_fractal *julia)
{
	double	zoom_factor;
	double	normalizedx;
	double	normalizedy;

	zoom_factor = 0.03;
	normalizedx = (2.0 * x / WIDTH) - 1.0;
	normalizedy = 1.0 - (2.0 * y / HEIGHT);
	if (button == ZOOM_OUT)
	{
		julia->scale *= 1.0 / (1.0 + zoom_factor);
		julia->move1 += normalizedy * (julia->move_step / julia->scale);
		julia->move -= normalizedx * (julia->move_step / julia->scale);
	}
	else if (button == ZOOM_IN)
	{
		julia->scale *= 1.0 + zoom_factor;
		julia->move1 += normalizedy * (julia->move_step / julia->scale);
		julia->move -= normalizedx * (julia->move_step / julia->scale);
	}
	if (button == 1)
		julia->binary = 1;
	else if (button == 2)
		julia->binary = 0;
	return (0);
}

int	mouse_sen_julia(int x, int y, t_fractal *julia)
{
	int		windowsize;
	int		half_window_size;
	double	normalizedx;
	double	normalizedy;

	windowsize = WIDTH;
	half_window_size = windowsize / 2;
	normalizedx = (x - half_window_size) / (double)half_window_size;
	windowsize = HEIGHT;
	half_window_size = windowsize / 2;
	normalizedy = (y - half_window_size) / (double)half_window_size;
	if (julia->binary == 1 && (x < 800 && x > 0 && y > 0 && y < 800))
	{
		julia->c_imaginary += julia->move_step / julia->scale * normalizedy;
		julia->c_real += julia->move_step / julia->scale * normalizedx;
	}
	else if (julia->binary == 0)
		;
	return (0);
}

int	render_next_frame_julia(void *param)
{
	t_fractal	*julia;

	julia = (t_fractal *)param;
	mlx_clear_window(julia->mlx, julia->win);
	draw_julia(julia);
	mlx_put_image_to_window(julia->mlx, julia->win, julia->img, 0, 0);
	return (0);
}
