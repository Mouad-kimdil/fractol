/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:31:47 by mkimdil           #+#    #+#             */
/*   Updated: 2024/01/30 23:42:32 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_call(t_fractal *julia)
{
	julia->mlx = mlx_init();
	julia->win = mlx_new_window(julia->mlx, 800, 800, "julia");
	julia->img = mlx_new_image(julia->mlx, 800, 800);
	julia->addr = mlx_get_data_addr(julia->img, &julia->bits_per_pixel,
			&julia->line_length, &julia->endian);
	julia->scale = 1.0;
	julia->gen_color = 5;
	julia->max_iter = 20;
	julia->width = 800;
	julia->height = 800;
	julia->move = 2.0;
	julia->move1 = 2.0;
	julia->move_step = 0.09;
	julia->move_step1 = -0.1;
	julia->c_imaginary = 0.4;
	julia->c_real = 0.4;
	mlx_hook(julia->win, 4, 0, key_mouse_julia, julia);
	mlx_hook(julia->win, 6, 0, mouse_sen_julia, julia);
	mlx_hook(julia->win, 2, 0, key_hook_julia, julia);
	mlx_loop_hook(julia->mlx, render_next_frame_julia, julia);
	mlx_loop(julia->mlx);
}
