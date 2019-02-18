/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:53:23 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/18 19:51:57 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include "parser.h"
# define WINDOW_X	1920
# define WINDOW_Y	1080
# define USG		1
# define MEM		2
# define ARG		3
# define MLX		4

typedef struct		s_img
{
	void			*image;
	int				*datas;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

typedef struct		s_pt
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
}					t_pt;

typedef struct		s_env
{
	void			*window;
	void			*mlx;
	char			*name;
	int				win_w;
	int				win_h;
	int				zoom;
	int				pixels;
	int				color;
	int				movex;
	int				movey;
	int				**iso;
	t_map			*map;
	t_img			*img;
	t_pt			*point;
}					t_env;

void				case1(t_env *env, t_pt pt);
void				case2(t_env *env, t_pt pt);
void				case3(t_env *env, t_pt pt);
void				case4(t_env *env, t_pt pt);
void				img_init(t_env *env, t_img *img);
void				draw(t_env *env);
void				refresh(t_env *env);
void				errors(int code);
void				display_usage(t_env *env);
void				init_iso_tab(t_map *map, t_env *env);
int					keylogger(int code, t_env *env);
int					**isometric_chart(t_env *env);
int					key_repeat(int key, t_env *env);
int					iso(t_env *env, int x, int y, int opt);

#endif
