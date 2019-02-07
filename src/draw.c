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
    draw(env);
    mlx_put_image_to_window(env->mlx, env->window, env->img->image, 0, 0);
    display_usage(env);
    mlx_destroy_image(env->mlx, env->img->image);
}

void draw_column(int i, t_env *env)
{
	t_pt pt;

	pt.x1 = env->iso[i][1];
	pt.x2 = env->iso[i + 1][1];
	// pt.y1 = env->iso[i][0];
	// pt.y2 = env->iso[i][1];
	// pt.dx = abs(pt.x2 - pt.x1);
	// pt.dy = abs(pt.y2 - pt.y1);
	// draw_segment(pt.x1, pt.y1, pt.x2, pt.y2, env);
}

void draw(t_env *env)
{
	int i;
	int x;

	i = -1;
	x = 1;
	while (++i < env->map->x_max * env->map->y_max)
	{
		if (i != (x * env->map->x_max))
			draw_column(i, env);
		else
			x++;

	}
}
