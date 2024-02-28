/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_helpers_julia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:37:31 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/28 03:17:28 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	generate_color_julia(int i, t_fractal *julia, int check)
{
	double	t;
	int		r;
	int		b;
	int		g;

	if (check == 1)
		return (0);
	t = (double)i / (double)julia->max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255)
		*log(log(julia->gen_color));
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255)
		*log(log(julia->gen_color));
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255)
		*log(log(julia->gen_color));
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put_julia(t_fractal *julia, int x, int y)
{
	char	*dst;

	dst = julia->addr + (y * julia->line_length
			+ x * (julia->bits_per_pixel / 8));
	*(unsigned int *)dst = julia->color;
}

void	juliate(t_fractal *julia, int x, int y)
{
	int			i;
	double		tmp;

	i = 0;
	julia->z_real = (double)x / (double)WIDTH
		* 4.1 / julia->scale - julia->move;
	julia->z_imaginary = (double)y / (double)HEIGHT
		* 4.1 / julia->scale - julia->move1;
	while (i < julia->max_iter)
	{
		tmp = julia->z_real * julia->z_real - julia->z_imaginary
			* julia->z_imaginary + julia->c_real;
		julia->z_imaginary = 2 * julia->z_real
			* julia->z_imaginary + julia->c_imaginary;
		julia->z_real = tmp;
		if (julia->z_real * julia->z_real
			+ julia->z_imaginary * julia->z_imaginary > 4)
			break ;
		i++;
	}
	if (i == julia->max_iter)
		julia->color = generate_color_julia(i, julia, 1);
	else
		julia->color = generate_color_julia(i, julia, 0);
}

void	draw_julia(t_fractal *julia)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			juliate(julia, x, y);
			my_mlx_pixel_put_julia(julia, x, y);
			y++;
		}
		x++;
	}
}
