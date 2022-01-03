/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:29:14 by gucamuze          #+#    #+#             */
/*   Updated: 2022/01/02 18:24:11 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fract_ol.h>

int	get_index_after_decimal(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == '.')
		{
			index++;
			break ;
		}
	}
	return (index);
}

double	ft_atod(char *str)
{
	double	first_part;
	double	second_part;
	double	negative;
	int		index_post_decimal;

	negative = 1;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	first_part = (double)ft_atoi(str);
	index_post_decimal = get_index_after_decimal(str);
	str += index_post_decimal;
	if (*str && ft_isdigit(*str))
		second_part = (double)ft_atoi(str);
	else
		second_part = 0;
	index_post_decimal = ft_strlen(str);
	while (index_post_decimal--)
		second_part /= 10;
	return ((first_part + second_part) * negative);
}

int	check_julia_arg(char *str)
{
	int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
	while (*str)
	{
		if (*str == '-')
		{
			if (flags[0] > 0)
				return (0);
			flags[0] += 1;
		}
		else if (*str == '.')
		{
			if (!flags[1] || flags[0] > 100)
				return (0);
			flags[0] += 100;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
		flags[1]++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1]) + 1))
			return (1);
		else if (!ft_strncmp(av[1], "julia", ft_strlen(av[1]) + 1))
		{
			if ((av[2] && av[3]) && check_julia_arg(av[2])
				&& check_julia_arg(av[3]))
				return (2);
			else
				print_arg_error(1);
		}
		else if (!ft_strncmp(av[1], "burning_ship", ft_strlen(av[1]) + 1))
			return (3);
		else
			print_arg_error(0);
	}
	else
		print_arg_error(0);
	return (0);
}

void	cleanup(t_data *data)
{
	free(data->plane);
	mlx_destroy_window(data->mlx->ptr, data->mlx->window);
	mlx_destroy_display(data->mlx->ptr);
	if (data->z)
		free(data->z);
	free(data->mlx->ptr);
	free(data->mlx);
	free(data);
}
