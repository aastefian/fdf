/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:57:56 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 16:00:02 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx-lib/mlx.h"
#include "../includes/fdf.h"

void	add_point(t_3d_p *point, int x, int y, int z)
{
	(*point).x = x;
	(*point).y = y;
	(*point).z = z;
}

void	put_point(void *mlx, void *win, t_3d_p point, int color)
{
	t_2d_p	ren_point;

	render(&ren_point, point);
	mlx_pixel_put(mlx, win, ren_point.x, ren_point.y, color);
}

void	put_line_h(t_mlx mini_l, t_2d_p ren_point1, t_2d_p ren_point2,
		int color)
{
	int x;

	x = ren_point1.x;
	while (x <= ren_point2.x)
	{
		mlx_pixel_put(mini_l.mlx, mini_l.win, x, ren_point1.y +
				((ren_point2.y - ren_point1.y) * (x - ren_point1.x)) /
				(ren_point2.x - ren_point1.x), color);
		x++;
	}
}

void	put_line_v(t_mlx mini_l, t_2d_p ren_point1, t_2d_p ren_point2,
		int color)
{
	int y;

	y = ren_point1.y;
	while (y <= ren_point2.y)
	{
		mlx_pixel_put(mini_l.mlx, mini_l.win, ren_point1.x +
				((y - ren_point1.y) * (ren_point2.x - ren_point1.x)) /
					(ren_point2.y - ren_point1.y), y, color);
		y++;
	}
}

void	put_line_handler(t_mlx mini_l, t_3d_p point1, t_3d_p point2,
		int color)
{
	t_2d_p	ren_point1;
	t_2d_p	ren_point2;
	float	m;

	render(&ren_point1, point1);
	render(&ren_point2, point2);
	m = (ren_point2.y - ren_point1.y) / (ren_point2.x - ren_point1.x);
	if (m >= -1 && m <= 1)
	{
		if (ren_point1.x <= ren_point2.x)
			put_line_h(mini_l, ren_point1, ren_point2, color);
		else
			put_line_h(mini_l, ren_point2, ren_point1, color);
	}
	else
	{
		if (ren_point1.y <= ren_point2.y)
			put_line_v(mini_l, ren_point1, ren_point2, color);
		else
			put_line_v(mini_l, ren_point2, ren_point1, color);
	}
}
