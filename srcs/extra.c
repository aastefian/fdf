/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:05:39 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 10:19:36 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	put_error(int code, char *language)
{
	if (code == 1 && ft_strcmp(language, "fr") == 0)
		ft_putstr("Le fichier n'existe pas\n");
	else if (code == 1)
		ft_putstr("The file doesn't exist\n");
	if (code == 2 && ft_strcmp(language, "fr") == 0)
		ft_putstr("Map invalide, elle doit contenir que des cifres\n");
	else if (code == 2)
		ft_putstr("Map not valid, it must contain only letters\n");
	if (code == 3 && ft_strcmp(language, "fr") == 0)
	{
		ft_putstr("Map pas bien structure.\n");
		ft_putstr("Il faut avoir le meme nombre des coordonees ");
		ft_putstr("sur chaque ligne\n");
	}
	else if (code == 3)
	{
		ft_putstr("Map is not well structured.\n");
		ft_putstr("You must have the same number of rows and columns.\n");
	}
	exit(EXIT_FAILURE);
}

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
