/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:06 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/30 14:33:00 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		cleanup(data);
		exit (0);
	}
	else if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
	{
		move_camera(data->plane, keycode);
		if (data->mode == 3)
			display_fractal_bs(data->mlx, data->plane, data->z);
		else
			display_fractal(data->mlx, data->plane, data->z);
	}
	else if (keycode == 114)
	{
		setup_plane(data->plane, data->mode);
		if (data->mode == 3)
			display_fractal_bs(data->mlx, data->plane, data->z);
		else
			display_fractal(data->mlx, data->plane, data->z);
	}
	return (1);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_and_display(data, 0);
	else if (button == 5)
		zoom_and_display(data, 1);
	return (1);
}

int	close_hook(t_data *data)
{
	cleanup(data);
	exit(0);
	return (1);
}
