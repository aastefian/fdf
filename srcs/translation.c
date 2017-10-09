/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:14:15 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 15:58:56 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	translate_left(void *param)
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
			(*data).map[x][y].y += LEFT_RIGHT_TRANSLATION_RATE;
			(*data).map[x][y].x -= LEFT_RIGHT_TRANSLATION_RATE;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	translate_right(void *param)
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
			(*data).map[x][y].y -= LEFT_RIGHT_TRANSLATION_RATE;
			(*data).map[x][y].x += LEFT_RIGHT_TRANSLATION_RATE;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	translate_up(void *param)
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
			(*data).map[x][y].y += UP_DOWN_TRANSLATION_RATE;
			(*data).map[x][y].x += UP_DOWN_TRANSLATION_RATE;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	translate_down(void *param)
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
			(*data).map[x][y].y -= UP_DOWN_TRANSLATION_RATE;
			(*data).map[x][y].x -= UP_DOWN_TRANSLATION_RATE;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}
