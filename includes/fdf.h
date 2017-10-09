/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:09:06 by svilau            #+#    #+#             */
/*   Updated: 2016/09/15 11:41:09 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEFAULT_COLOR 16777215
# define BUFF_SIZE 1
# define GROUND_SCALE 30
# define HEIGHT_SCALE 1
# define ORIGIN_X 550
# define ORIGIN_Y 600
# define CONST 0.5
# define CONST2 0.5
# define MAX_ZOOM_OUT 8
# define MAX_ZOOM_IN 8
# define ZOOM_RATE 1.1
# define LEFT_RIGHT_TRANSLATION_RATE 5
# define UP_DOWN_TRANSLATION_RATE 5
# define HEIGHT_TRANSLATION_RATE 8.5
# define HEIGHT_MAX 5

typedef struct		s_mlx
{
	void *mlx;
	void *win;
}					t_mlx;

typedef struct		s_size
{
	int height;
	int width;
}					t_size;

typedef struct		s_2d_p
{
	float	x;
	float	y;
	int		color;
}					t_2d_p;

typedef struct		s_3d_p
{
	float	x;
	float	y;
	float	z;
	int		color;
	char	end;
}					t_3d_p;

typedef struct		s_data
{
	t_mlx	mini_l;
	t_3d_p	**map;
}					t_data;

void				print_instructions(char *str);
int					get_next_line(int fd, char **line);
int					word_count(char *str);
int					width_count(t_3d_p **map);
int					height_count(t_3d_p **map);
int					line_count(char *file_name);
void				add_point(t_3d_p *point, int x, int y, int z);
void				put_point(void *mlx, void *win, t_3d_p point, int color);
void				put_line_handler(t_mlx mini_l, t_3d_p point1, t_3d_p point2,
						int color);
void				check_map_first(char *file_name, char *language);
void				check_map_second(t_3d_p **map, char *language);
void				put_map(t_mlx mini_l, t_3d_p **map);
void				clear_window(void *param);
void				get_map(char *file_name, t_3d_p ***map, char *language);
void				put_error(int code, char *language);
void				render(t_2d_p *ren_point, t_3d_p point);
void				translate_left(void *param, int nb);
void				translate_right(void *param, int nb);
void				translate_up(void *param);
void				translate_down(void *param);
void				rotate_z(void *param);
void				rotate_x(void *param);
void				rotate_y(void *param);
void				height_up(void *param);
void				height_down(void *param);
void				zoom_handler(int keycode, void *param);

#endif
