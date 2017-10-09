/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:19:16 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 15:59:36 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	height_up(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			if ((*data).map[x][y].z != 0)
				(*data).map[x][y].z += HEIGHT_TRANSLATION_RATE *
					((*data).map[x][y].z / 10);
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	height_down(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			if ((*data).map[x][y].z != 0)
				(*data).map[x][y].z -= HEIGHT_TRANSLATION_RATE
				* ((*data).map[x][y].z / 20);
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}
