/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:16:13 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/19 04:44:44 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	generate_color(int i, t_vars *vars, int check)
{
	if (check == 1)
		return (0);
	return (((i * vars->max_iter) << 4) * vars->gen_color);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = data->color;
}

void	mandelbrot(t_complex c, t_vars *vars)
{
	t_complex	z;
	int			i;
	double		temp;

	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < vars->max_iter)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		if (z.real * z.real + z.imaginary * z.imaginary > 4)
			break ;
		i++;
	}
	if (i == vars->max_iter)
		vars->color = generate_color(i, vars, 1);
	else
		vars->color = generate_color(i, vars, 0);
}

void	draw_mandelbrot(t_vars *vars)
{
	int			x;
	int			y;
	t_complex	c;
	double		inv_width_scale;
	double		inv_height_scale;

	x = 0;
	inv_width_scale = 4.0 / (WIDTH * vars->scale + vars->move);
	inv_height_scale = 4.0 / (HEIGHT * vars->scale + vars->move1);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.real = (x - WIDTH / 2.0) * inv_width_scale + vars->center_real;
			c.imaginary = (y - HEIGHT / 2.0) * inv_height_scale
				+ vars->center_imaginary;
			mandelbrot(c, vars);
			my_mlx_pixel_put(vars, x, y);
			y++;
		}
		x++;
	}
}
