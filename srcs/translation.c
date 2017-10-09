/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:14:15 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 10:34:30 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	translate_left(void *param, int nb)
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
			(*data).map[x][y].y += nb;
			(*data).map[x][y].x -= nb;
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	translate_right(void *param, int nb)
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
			(*data).map[x][y].y -= nb;
			(*data).map[x][y].x += nb;
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
