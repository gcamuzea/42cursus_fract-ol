/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:01:22 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/02 18:21:47 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

t_data	*setup(int mode, char **av)
{
	t_plane		*plane;
	t_data		*data;
	t_complex	*z;

	plane = malloc(sizeof(t_plane));
	data = malloc(sizeof(t_data));
	z = NULL;
	if (!plane || !data)
		return (NULL);
	if (mode == 2)
	{
		z = malloc(sizeof(t_complex));
		if (!z)
			return (NULL);
		z->rn = ft_atod(av[2]);
		z->in = ft_atod(av[3]);
	}
	setup_plane(plane, mode);
	setup_mlx(data);
	data->mode = mode;
	data->plane = plane;
	data->z = z;
	return (data);
}

void	setup_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit(0);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit(0);
	mlx->window = mlx_new_window(mlx->ptr, W_LEN, W_HGT, "fract-ol");
	mlx_hook(mlx->window, 2, 1L << 0, key_hook, data);
	mlx_hook(mlx->window, 4, 1L << 2, mouse_hook, data);
	mlx_hook(mlx->window, 17, 1L << 17, close_hook, data);
	data->mlx = mlx;
}

void	print_arg_error(int mode)
{
	if (!mode)
	{
		printf("Error: wrong arguments given. Usage: ./fract-ol ");
		printf("[mandelbrot], [julia [n1][n2]], [burning_ship]\n");
	}
	else if (mode)
		printf("Invalid or missing options for Julia set, try again\n");
}
