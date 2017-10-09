/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:53:29 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 10:38:21 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	rotate_z(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	float	i;
	float	j;

	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			i = (*data).map[x][y].x;
			j = (*data).map[x][y].y;
			(*data).map[x][y].x = i * cos(M_PI_4) - j * sin(M_PI_4);
			(*data).map[x][y].y = i * sin(M_PI_4) + j * cos(M_PI_4);
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	rotate_x(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	float	i;
	float	j;

	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			i = (*data).map[x][y].y;
			j = (*data).map[x][y].z;
			(*data).map[x][y].y = i * cos(M_PI_4) - j * sin(M_PI_4);
			(*data).map[x][y].z = i * sin(M_PI_4) + j * cos(M_PI_4);
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}

void	rotate_y(void *param)
{
	t_data	*data;
	int		x;
	int		y;
	float	i;
	float	j;

	data = (t_data*)param;
	x = 0;
	clear_window(param);
	while ((*data).map[x])
	{
		y = 0;
		while ((*data).map[x][y].end)
		{
			i = (*data).map[x][y].z;
			j = (*data).map[x][y].x;
			(*data).map[x][y].z = i * cos(M_PI_4) - j * sin(M_PI_4);
			(*data).map[x][y].x = i * sin(M_PI_4) + j * cos(M_PI_4);
			(*data).map[x][y].color = DEFAULT_COLOR;
			y++;
		}
		x++;
	}
	put_map((*data).mini_l, (*data).map);
}
