/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:50 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/03 22:27:25 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <libft.h>
# include <math.h>

# define ITER 80
# define W_LEN 1920
# define W_HGT 1080

typedef struct s_mlx_img {
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
}				t_mlx_img;

typedef struct s_mlx {
	void		*ptr;
	void		*window;
}				t_mlx;

typedef struct s_plane {
	double		rn_start;
	double		rn_end;
	double		in_start;
	double		in_end;
	double		rn_magnitude;
	double		in_magnitude;
	double		rn_ipp;
	double		in_ipp;
}				t_plane;

typedef struct s_complex {
	double		rn;
	double		in;
}				t_complex;

typedef struct s_data
{
	t_mlx		*mlx;
	t_plane		*plane;
	t_complex	*z;
	int			mode;
}				t_data;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

t_data	*setup(int mode, char **av);
void	setup_mlx(t_data *data);
int		check_julia_arg(char *str);
int		check_args(int ac, char **av);
void	print_arg_error(int mode);
void	cleanup(t_data *data);
double	ft_atod(char *str);

void	move_camera_left(t_plane *plane);
void	move_camera_right(t_plane *plane);
void	move_camera_up(t_plane *plane);
void	move_camera_down(t_plane *plane);
void	move_camera(t_plane *plane, int keycode);

int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_hook(t_data *data);

void	zoom_and_display(t_data *data, int mode);
void	reset_plane(t_data *data);

void	display_fractal(t_mlx *mlx, t_plane *plane, t_complex *z);
double	is_in_set(t_complex c, t_complex *z);
double	magnitude(t_complex c);

double	is_in_set_bs(t_complex c, t_complex *z);
void	display_fractal_bs(t_mlx *mlx, t_plane *plane, t_complex *z);

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, double iter);
int		get_color(double mandelbrot_return);
void	setup_plane(t_plane *plane, int mode);

#endif