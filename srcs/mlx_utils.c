/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:30:32 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/30 14:55:42 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, double iter)
{
	char	*dst;
	int		color;

	color = 0x0;
	if (iter < ITER)
		color = get_color(iter);
	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(double mandelbrot_return)
{
	int		color;

	color = (mandelbrot_return * mandelbrot_return) + 1;
	return (create_trgb(0, 69, color, 200));
}

void	setup_plane(t_plane *plane, int mode)
{
	if (mode == 3)
	{
		plane->rn_start = -2.5;
		plane->rn_end = 1.25;
		plane->in_start = -1.25;
		plane->in_end = 1.25;
	}
	else
	{
		plane->rn_start = -2.5;
		plane->rn_end = 1.25;
		plane->in_start = 1.25;
		plane->in_end = -1.25;
	}
}
