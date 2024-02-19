#include "fractol.h"

void	my_fractal_call(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "burning_ship");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
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
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 4, 0, key_mouse, vars);
	mlx_loop_hook(vars->mlx, my_fract_render_next_frame, vars);
	mlx_loop(vars->mlx);
}