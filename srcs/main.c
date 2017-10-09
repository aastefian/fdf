/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:19:01 by svilau            #+#    #+#             */
/*   Updated: 2016/09/14 09:41:07 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx-lib/mlx.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	print_instructions(char *str)
{
	if (ft_strcmp(str, "fr") == 0)
	{
		ft_putstr("Utilisez les fleshes pour bouger l'objet\n");
		ft_putstr("z => Rotation sur l'axe z\n");
		ft_putstr("y => Rotation sur l'axe y\n");
		ft_putstr("x => Rotation sur l'axe x\n");
		ft_putstr("+ => Agrandir\n");
		ft_putstr("- => Rapetisser\n");
		ft_putstr("PgUp => Augmenter l'altitude\n");
		ft_putstr("PgDown => Diminuer l'altitude\n");
	}
	else
	{
		ft_putstr("Use arrows to move the object\n");
		ft_putstr("z => Rotation on z axis\n");
		ft_putstr("y => Rotation on y axis\n");
		ft_putstr("x => Rotation on x axis\n");
		ft_putstr("+ => Zoom in\n");
		ft_putstr("- => Zoom out\n");
		ft_putstr("PgUp => Raise altitude\n");
		ft_putstr("PgDown => Lower altitude\n");
	}
}

int		key_handler(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 78)
		zoom_handler(keycode, param);
	else if (keycode == 123)
		translate_left(param);
	else if (keycode == 124)
		translate_right(param);
	else if (keycode == 126)
		translate_up(param);
	else if (keycode == 125)
		translate_down(param);
	else if (keycode == 116)
		height_up(param);
	else if (keycode == 121)
		height_down(param);
	else if (keycode == 6)
		rotate_y(param);
	else if (keycode == 7)
		rotate_x(param);
	else if (keycode == 16)
		rotate_z(param);
	return (0);
}

void	event_handler(t_mlx mini_l, t_3d_p ***map)
{
	t_data *data;

	data = NULL;
	data = (t_data*)malloc(sizeof(t_data) * 1);
	(*data).mini_l = mini_l;
	(*data).map = *map;
	mlx_key_hook(mini_l.win, key_handler, data);
}

int		fdf(t_3d_p ***map)
{
	t_mlx	mini_l;

	mini_l.mlx = mlx_init();
	mini_l.win = mlx_new_window(mini_l.mlx, 800, 800, "FdF Beta v1.0");
	put_map(mini_l, *map);
	event_handler(mini_l, map);
	mlx_loop(mini_l.mlx);
	return (1);
}

int		main(int ac, char **av)
{
	t_3d_p	**map;

	map = NULL;
	if (ac == 3)
	{
		check_map_first(av[1], av[2]);
		get_map(av[1], &map, av[2]);
		check_map_second(map, av[2]);
		print_instructions(av[2]);
		fdf(&map);
	}
	else
		ft_putstr("Utilisation: ./fdf [map file] [language]\n");
	return (0);
}
