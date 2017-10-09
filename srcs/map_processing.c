/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:53:36 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 09:41:02 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	check_map_first(char *file_name, char *language)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		put_error(1, language);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i])
		{
			if (ft_isalpha(line[i]))
				put_error(2, language);
			i++;
		}
	}
}

void	check_map_second(t_3d_p **map, char *language)
{
	int x;
	int y;
	int t;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y].end)
			y++;
		if (x == 0)
			t = y;
		if (y != t)
			put_error(3, language);
		x++;
	}
	//if (x == 0 && map[x] == NULL)
	//	put_error(4, language);
}

void	assign_map(t_3d_p ***map, char **temp, int width, int x)
{
	int i;
	int y;

	i = 0;
	y = width - 1;
	while (temp[i] && y >= 0)
	{
		(*map)[x][y].z = ft_atoi(temp[i]) * HEIGHT_SCALE;
		(*map)[x][y].x = x * GROUND_SCALE;
		(*map)[x][y].y = y * GROUND_SCALE;
		(*map)[x][y].color = DEFAULT_COLOR;
		(*map)[x][y].end = '0';
		i++;
		y--;
	}
	(*map)[x][width].end = '\0';
}

void	get_map(char *file_name, t_3d_p ***map, char *language)
{
	t_size	size;
	int		fd;
	int		x;
	char	*line;
	char	**temp;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		put_error(1, language);
	size.height = line_count(file_name);
	x = size.height - 1;
	if (!(*map = (t_3d_p **)malloc(sizeof(t_3d_p *) * (size.height + 1))))
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		size.width = word_count(line);
		if (!((*map)[x] = (t_3d_p *)malloc(sizeof(t_3d_p) * (size.width + 1))))
			return ;
		temp = ft_strsplit(line, ' ');
		assign_map(map, temp, size.width, x);
		free(temp);
		x--;
	}
	(*map)[size.height] = NULL;
	close(fd);
}
