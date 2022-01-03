/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:49:22 by gucamuze          #+#    #+#             */
/*   Updated: 2021/12/30 13:48:01 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

int	main(int ac, char **av)
{
	t_data	*data;
	int		mode;

	mode = check_args(ac, av);
	if (!mode)
		exit(0);
	data = setup(mode, av);
	if (!data)
		exit(0);
	if (mode == 3)
		display_fractal_bs(data->mlx, data->plane, data->z);
	else
		display_fractal(data->mlx, data->plane, data->z);
	mlx_loop(data->mlx->ptr);
}
