/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:21:39 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/16 14:52:07 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define ITER_UP 7
# define ITER_DOWN 8
# define COLOR_UP 34
# define COLOR_DOWN 32
# define JULIA 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	center_real;
	double	center_imaginary;
	double	scale;
	double	move;
	double	move1;
	double	move_step;
	int		max_iter;
	int		color;
	int		gen_color;
	int		mouse_x;
	int		mouse_y;
}	t_vars;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	scale;
	int		max_iter;
	int		color;
	int		gen_color;
	int		mouse_x;
	int		mouse_y;
	double	c_real;
	double	c_imaginary;
	double	z_real;
	double	z_imaginary;
	double	move1;
	double	move;
	double	move_step;
	double	move_step1;
	int		binary;
}	t_fractal;

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif

int		close_window(void *param);
int		key_hook_julia(int keycode, t_fractal *julia);
int		key_mouse_julia(int button, int x, int y, t_fractal *julia);
int		mouse_sen_julia(int x, int y, t_fractal *julia);
int		render_next_frame_julia(void *param);
int		generate_color_julia(int i, t_fractal *julia, int check);
void	my_mlx_pixel_put_julia(t_fractal *julia, int x, int y);
void	draw_julia(t_fractal *julia);
void	juliate(t_fractal *julia, int x, int y);
int		generate_color(int i, t_vars *vars, int check);
void	my_mlx_pixel_put(t_vars *data, int x, int y);
void	draw_mandelbrot(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		render_next_frame(void *vars);
void	mandelbrot(t_complex c, t_vars *vars);
int		key_mouse(int button, int x, int y, t_vars *vars);
int		ft_strncmp(char *s1, char *s2, int len);
void	julia_call(t_fractal *julia);
void	mandelbrot_call(t_vars *vars);
void	my_fractal_call(t_vars *vars);
int		my_fract_render_next_frame(void *param);
void	draw_my_fractal(t_vars *vars, int width, int height);
void	my_fractal(t_complex c, t_vars *vars);
int		burn_key_hook(int keycode, t_vars *vars);
int		burn_key_mouse(int button, int x, int y, t_vars *vars);
int		burn_generate_color(int i, t_vars *vars, int is_max_iter);
void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *str);
void	initialize_julia(t_fractal *julia);
void	my_exit(char *str);
void	initialize_mandelbrot(t_vars *vars);
void	initialize_burning(t_vars *vars);

#endif