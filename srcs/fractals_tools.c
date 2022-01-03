/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:34 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/30 14:53:36 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

double	magnitude(t_complex c)
{
	return (sqrt((c.rn * c.rn) + (c.in * c.in)));
}

double	is_in_set(t_complex c, t_complex *z)
{
	t_complex	mz;
	double		swap_rn;
	int			n;

	if (!z)
	{
		mz.rn = 0;
		mz.in = 0;
	}
	else
	{
		mz.rn = z->rn;
		mz.in = z->in;
	}
	n = 0;
	while (magnitude(mz) <= 2 && ++n < ITER)
	{
		swap_rn = mz.rn;
		mz.rn = (mz.rn * mz.rn) + (-1 * (mz.in * mz.in)) + c.rn;
		mz.in = 2 * swap_rn * mz.in + c.in;
	}
	if (n == ITER)
		return (n);
	return (n + 1 - log(log2(magnitude(mz))));
}

void	display_fractal(t_mlx *mlx, t_plane *p, t_complex *z)
{
	t_complex	c;
	t_mlx_img	img;
	double		v_px;
	double		h_px;
	double		iter;

	img.img = mlx_new_image(mlx->ptr, W_LEN, W_HGT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	v_px = -1;
	while (++v_px < W_HGT)
	{
		h_px = -1;
		c.in = p->in_start + (v_px / W_HGT) * (p->in_end - p->in_start);
		while (++h_px < W_LEN)
		{
			c.rn = p->rn_start + (h_px / W_LEN) * (p->rn_end - p->rn_start);
			if (!z)
				iter = is_in_set(c, z);
			else
				iter = is_in_set(*z, &c);
			my_mlx_pixel_put(&img, h_px, v_px, iter);
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->window, img.img, 0, 0);
	mlx_destroy_image(mlx->ptr, img.img);
}
