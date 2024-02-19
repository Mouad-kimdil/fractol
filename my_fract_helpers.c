#include "fractol.h"

void	my_fractal(t_complex c, t_vars *vars)
{
	t_complex	z;
	int			i;
	double		temp;

	z.real = 0.0;
	z.imaginary = 0.0;
	i = 0;
	while (i < vars->max_iter)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = -2 * z.real * z.imaginary + c.imaginary;
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

void	draw_my_fractal(t_vars *vars, int width, int height)
{
	int			x;
	int			y;
	t_complex	c;
	double		inv_width_scale;
	double		inv_height_scale;

	x = 0;
	inv_width_scale = 4.0 / (width * vars->scale + vars->move);
	inv_height_scale = 4.0 / (height * vars->scale + vars->move1);
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			c.real = (x - width / 2.0) * inv_width_scale + vars->center_real;
			c.imaginary = (y - height / 2.0) * inv_height_scale
				+ vars->center_imaginary;
			my_fractal(c, vars);
			my_mlx_pixel_put(vars, x, y);
			y++;
		}
		x++;
	}
}

int	my_fract_render_next_frame(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	draw_my_fractal(vars, WIDTH, HEIGHT);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}