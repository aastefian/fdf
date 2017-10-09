/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:16:47 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 15:58:37 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_in(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	int		black;

	black = 0;
	data = (t_data*)param;
	clear_window(param);
	x = 0;
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			(*data).map[x][y].x *= ZOOM_RATE;
			(*data).map[x][y].y *= ZOOM_RATE;
			(*data).map[x][y].color = 16777215;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	zoom_out(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	int		black;

	black = 0;
	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			(*data).map[x][y].x /= ZOOM_RATE;
			(*data).map[x][y].y /= ZOOM_RATE;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	zoom_handler(int keycode, void *param)
{
	static int zo;
	static int zi;

	if (keycode == 69)
	{
		if (zi < MAX_ZOOM_IN)
		{
			zoom_in(param);
			zi += 1;
			zo -= 1;
		}
	}
	else if (keycode == 78)
	{
		if (zo < MAX_ZOOM_OUT)
		{
			zoom_out(param);
			zo += 1;
			zi -= 1;
		}
	}
}
