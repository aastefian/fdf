/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_processing_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:14:27 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 15:59:42 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx-lib/mlx.h"

void	wireframing(t_mlx mini_l, t_3d_p **map, t_size map_size, t_2d_p coord)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mini_l.mlx;
	win = mini_l.win;
	x = coord.x;
	y = coord.y;
	if (y + 1 >= 0 && y + 1 < map_size.height)
		put_line_handler(mini_l, map[x][y + 1], map[x][y], coord.color);
	if (y - 1 >= 0 && y - 1 < map_size.height)
		put_line_handler(mini_l, map[x][y - 1], map[x][y], coord.color);
	if (x + 1 >= 0 && x + 1 < map_size.width)
		put_line_handler(mini_l, map[x + 1][y], map[x][y], coord.color);
	if (x - 1 >= 0 && x - 1 < map_size.width)
		put_line_handler(mini_l, map[x - 1][y], map[x][y], coord.color);
}

void	clear_window(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	int		black;

	black = 0;
	data = (t_data*)param;
	x = 0;
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			(*data).map[x][y].color = black;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	put_map(t_mlx mini_l, t_3d_p **map)
{
	int		x;
	int		y;
	t_2d_p	coord;
	t_size	map_size;

	x = 0;
	map_size.width = width_count(map);
	map_size.height = height_count(map);
	while (map[x])
	{
		y = 0;
		while (map[x][y].end)
		{
			put_point(mini_l.mlx, mini_l.win, map[x][y], map[x][y].color);
			coord.x = x;
			coord.y = y;
			coord.color = map[x][y].color;
			wireframing(mini_l, map, map_size, coord);
			y++;
		}
		x++;
	}
}
