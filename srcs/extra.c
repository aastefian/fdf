/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:05:39 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 10:06:08 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <Stdio.h>

int		word_count(char *str)
{
	int word;
	int i;

	word = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		word++;
		while (str[i] == ' ')
			i++;
	}
	return (word);
}

int		line_count(char *file_name)
{
	int		fd;
	int		ret;
	int		lines;
	char	buff[BUFF_SIZE + 1];

	lines = 0;
	fd = open(file_name, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
			lines++;
	}
	if (ret)
		lines++;
	close(fd);
	return (lines);
}

int		width_count(t_3d_p **map)
{
	int x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int		height_count(t_3d_p **map)
{
	int y;

	y = 0;
	if (map[0])
	{
	while (map[0][y].end)
		y++;
	}
	return (y);
}
