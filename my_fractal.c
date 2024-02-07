#include "fractol.h"

void	my_fractal_call(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "my_fractal");
	vars->img = mlx_new_image(vars->mlx, 800, 800);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->center_real = 0.0;
	vars->center_imaginary = 0.0;
	vars->scale = 1.0;
	vars->gen_color = 255;
	vars->max_iter = 80;
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 4, 0, key_mouse, vars);
	mlx_loop_hook(vars->mlx, my_fract_render_next_frame, vars);
	mlx_loop(vars->mlx);
}