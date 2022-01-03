/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:07:46 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/09 16:43:42 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

void	move_camera_left(t_plane *plane)
{
	double	movement_size;

	movement_size = (plane->rn_end - plane->rn_start) / 10;
	plane->rn_start -= movement_size;
	plane->rn_end -= movement_size;
}

void	move_camera_right(t_plane *plane)
{
	double	movement_size;

	movement_size = (plane->rn_end - plane->rn_start) / 10;
	plane->rn_start += movement_size;
	plane->rn_end += movement_size;
}

void	move_camera_up(t_plane *plane)
{
	double	movement_size;

	movement_size = (plane->in_end - plane->in_start) / 10;
	plane->in_start += movement_size;
	plane->in_end += movement_size;
}

void	move_camera_down(t_plane *plane)
{
	double	movement_size;

	movement_size = (plane->in_end - plane->in_start) / 10;
	plane->in_start -= movement_size;
	plane->in_end -= movement_size;
}

void	move_camera(t_plane *plane, int keycode)
{
	if (keycode == 65361)
		move_camera_left(plane);
	else if (keycode == 65363)
		move_camera_right(plane);
	else if (keycode == 65362)
		move_camera_down(plane);
	else if (keycode == 65364)
		move_camera_up(plane);
}
