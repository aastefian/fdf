/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_axes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:01:50 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 16:02:55 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx-lib/mlx.h"

void put_axes(void *mlx, void *win, t_3d_p point, int color)
{
	t_2d_p ren_point;
	int pixel_x;
	int pixel_y;
	char *str;
	
	if (point.x != 0)
		str = "x";
	else if (point.y != 0)
		str = "y";
	else if (point.z != 0)
		str = "z";
	else
		str = "O";
	render(&ren_point, point);
	mlx_pixel_put(mlx, win, ren_point.x, ren_point.y, color);
	mlx_string_put(mlx, win, ren_point.x, ren_point.y, color, str);
}

void put_axes_handler(void *mlx, void *win)
{
	t_3d_p x_axis;
	t_3d_p y_axis;
	t_3d_p z_axis;
	t_3d_p o_axis;

	add_point(&x_axis, 100, 0, 0);
	add_point(&y_axis, 0, 100, 0);
	add_point(&z_axis, 0, 0, 100);
	add_point(&o_axis, 0, 0, 0);
	put_axes(mlx, win, x_axis, 16777215);
	put_axes(mlx, win, y_axis, 16777215);
	put_axes(mlx, win, z_axis, 16777215);
	put_axes(mlx, win, o_axis, 16777215);
	put_line_handler(mlx, win, o_axis, x_axis, 16777215);
	put_line_handler(mlx, win, o_axis, z_axis, 16777215);
	put_line_handler(mlx, win, o_axis, y_axis, 16777215);
}
