/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:26:21 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/30 14:29:41 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

void	zoom_and_display(t_data *data, int mode)
{
	double	rn_amplitude;
	double	in_amplitude;

	rn_amplitude = (data->plane->rn_end - data->plane->rn_start) / 10;
	in_amplitude = (data->plane->in_end - data->plane->in_start) / 10;
	if (mode)
	{
		data->plane->rn_start += rn_amplitude;
		data->plane->rn_end -= rn_amplitude;
		data->plane->in_start += in_amplitude;
		data->plane->in_end -= in_amplitude;
	}
	else
	{
		data->plane->rn_start -= rn_amplitude;
		data->plane->rn_end += rn_amplitude;
		data->plane->in_start -= in_amplitude;
		data->plane->in_end += in_amplitude;
	}
	if (data->mode == 3)
		display_fractal_bs(data->mlx, data->plane, data->z);
	else
		display_fractal(data->mlx, data->plane, data->z);
}
