/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:22:2 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/04 16:04:58 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void display_usage(t_env *env)
{
    int x;
    int y;

    x = WINDOW_X - 230;
    y = 20;
    mlx_string_put(env->mlx, env->window, x + 40, y, 0xFFFFFF,
					"--- COMMANDS ---");
    mlx_string_put(env->mlx, env->window, x + 40, y + 30, 0xFFFFFF,
					"Exit      Escape");
	mlx_string_put(env->mlx, env->window, x + 40, y + 60, 0xFFFFFF,
					"Move      Arrows");
	mlx_string_put(env->mlx, env->window, x + 40, y + 90, 0xFFFFFF,
					"Zoom      	+    -");
	mlx_string_put(env->mlx, env->window, x + 40, y + 120, 0xFFFFFF,
					"Relief    	R    E");
}	

void img_init(t_env *env, t_img *img)
{
    img->image = mlx_new_image(env->mlx, env->win_w, env->win_h);
    img->datas = (int *)mlx_get_data_addr(img->image, &img->bpp,
                                          &img->s_line, &img->endian);
}

int iso(t_map *map, int x, int y, int opt)
{
	int z;

	z = map->points[x][y];
	/* X case */
	if (opt == 1)
		return ((x - y) * cos(0.523599));
	else
		return (-z + (x + y) * sin(0.523599));
}

void init_iso_tab(t_map *map, t_env *env)
{
	int i;
	int **tab;

	i = -1;
	if (!(tab = (int**) malloc(sizeof(int*) * (map->x_max * map->y_max))))
		exit(1);
	while (++i < map->x_max * map->y_max)
		if (!(tab[i] = (int*) malloc(sizeof(int) * 2)))
			exit(1);
	env->iso = tab;
}

void apply_iso(t_env *env)
{
    int x;
    int y;
	int i;

    x = -1;
	i = -1;
	init_iso_tab(env->map, env);
    while (++x < env->map->x_max)
    {
        y = -1;
        while (++y < env->map->y_max)
        {
            env->iso[++i][0] = iso(env->map, x, y, 1);
			env->iso[i][1] = iso(env->map, x, y, 0);
        }
    }
}

void refresh(t_env *env)
{
    t_img img;

    img.image = mlx_new_image(env->mlx, env->win_w, env->win_h);
    img.datas = (int *)mlx_get_data_addr(img.image, &img.bpp,
                                         &img.s_line, &img.endian);
    env->img = &img;
    apply_iso(env);
    // draw(env);
    mlx_put_image_to_window(env->mlx, env->window,
                            env->img->image, 0, 0);
    display_usage(env);
    mlx_destroy_image(env->mlx, env->img->image);
}

void draw_line(t_env *env, int x, int y)
{
    draw_segment(x * env->zoom, y * env->zoom, x * env->zoom, y * env->zoom, env);
}

// void        draw_column(t_env *env, int x, int y, int x2, int y2)
// {
//     draw_segment(x * env->zoom, y * env->zoom, env->point->x1 * env->point->x1, y * env->zoom, env);
// }

void draw(t_env *env)
{
    int x;
    int y;

    x = -1;
    while (++x < env->map->x_max)
    {
        y = -1;
        while (++y < env->map->y_max)
        {
            if (env->map->points[x][y] > 0)
            {
                draw_line(env, y, x);
            }
            // draw_column(env, y, x);
        }
    }
}
