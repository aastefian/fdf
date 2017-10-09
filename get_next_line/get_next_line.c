/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <svilau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:28:11 by svilau            #+#    #+#             */
/*   Updated: 2016/05/19 16:40:23 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int		check_endline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_replace_str(char **dest, char *src, unsigned int pos)
{
	int i;
	int size;

	i = 0;
	size = (ft_strlen(src) - pos) + 1;
	free(*dest);
	*dest = ft_strnew(size);
	while (src[pos])
	{
		(*dest)[i] = src[pos];
		pos++;
		i++;
	}
	(*dest)[size] = '\0';
}

char	*ft_add2str(char *dest, char *src)
{
	char			*temp;
	size_t			val_length;
	size_t			i;
	unsigned int	size;

	size = ft_strlen(dest) + ft_strlen(src);
	temp = (char*)malloc((size + 1) * sizeof(char));
	val_length = 0;
	while (dest != '\0' && dest[val_length])
	{
		temp[val_length] = dest[val_length];
		val_length++;
	}
	i = 0;
	while (i < (size - val_length))
	{
		temp[val_length + i] = src[i];
		i++;
	}
	temp[val_length + i] = '\0';
	free(dest);
	return (temp);
}

int		data_handler(char **line, char **data, char **buff)
{
	char *tmp;
	char *data_tmp;

	if (check_endline(*buff) != -1)
	{
		tmp = ft_strsub(*buff, 0, check_endline(*buff));
		*line = ft_add2str(*line, tmp);
		free(tmp);
		data_tmp = ft_strsub(*buff, 0, ft_strlen(*buff));
		ft_replace_str(data, data_tmp,
				check_endline(data_tmp) + 1);
		return (1);
	}
	else
	{
		*line = ft_add2str(*line, *buff);
		ft_strclr(*buff);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buff;
	static char	*leftover;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = '\0';
	if (leftover && data_handler(line, &leftover, &leftover) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (data_handler(line, &leftover, &buff) == 1)
			return (1);
	}
	return ((*line)[0] != '\0');
}
