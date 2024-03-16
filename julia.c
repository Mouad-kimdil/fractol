/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:31:47 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/16 22:38:55 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_julia(t_fractal *julia)
{
	julia->mlx = mlx_init();
	if (!julia->mlx)
		my_exit(INIT_FAILED);
	julia->win = mlx_new_window(julia->mlx, WIDTH, HEIGHT, "julia");
	if (!julia->win)
		my_exit(NEW_WIN_FAILED);
	julia->img = mlx_new_image(julia->mlx, WIDTH, HEIGHT);
	if (!julia->img)
		my_exit(NEW_IMG_FAILED);
	julia->addr = mlx_get_data_addr(julia->img, &julia->bits_per_pixel,
			&julia->line_length, &julia->endian);
	if (!julia->addr)
		my_exit(GET_DATA_ADDR_FAILED);
	julia->scale = 1.0;
	julia->gen_color = 5;
	julia->max_iter = 20;
	julia->move = 2.0;
	julia->move1 = 2.0;
	julia->move_step = 0.09;
	julia->move_step1 = -0.09;
	julia->c_real = -0.4;
	julia->c_imaginary = -0.6;
	julia->temp_r = julia->c_real;
	julia->temp_i = julia->c_imaginary;
}

void	julia_call(t_fractal *julia)
{
	initialize_julia(julia);
	mlx_hook(julia->win, 17, 0, close_window, julia);
	mlx_hook(julia->win, 4, 0, key_mouse_julia, julia);
	mlx_hook(julia->win, 6, 0, mouse_sen_julia, julia);
	mlx_hook(julia->win, 2, 0, key_hook_julia, julia);
	mlx_loop_hook(julia->mlx, render_next_frame_julia, julia);
	mlx_loop(julia->mlx);
}
