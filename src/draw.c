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

int iso(t_env *env, int x, int y, int opt)
{
	int z;

	z = env->map->points[x][y];
	/* X case */
	if (opt == 1)
			return (((x * cos(-1) * env->zoom + y *
						cos(-1 + 2) * env->zoom + z
						* 1 * cos(-1 - 2)
						* env->zoom / 30 * 2) + (env->win_h / 4))
				+ 2 * 50);
	else
		return (((x * sin(-1) * env->zoom + y *
						sin(-1 + 2) * env->zoom
						+ z * 1 * sin(-1 - 2)
						* env->zoom / 30 * env->win_h)
					+ (env->win_w / 2.25)) + 1 * 50);
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
            env->iso[++i][0] = iso(env, x, y, 1);
			env->iso[i][1] = iso(env, x, y, 0);
			env->iso[i][0] += env->movex;
			env->iso[i][1] += env->movey;
			printf("%d ", env->iso[i][1]);
			printf("%d\n", env->iso[i][0]);
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


void ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void	case1(t_env *env, t_pt pt)
{

	int		neg;
	float	a;
	int		i;

	neg = 1;
	a = 0;
	i = 0;
	if (pt.x1 > pt.x2)
	{
		neg = -1;
		ft_swap(&pt.x1, &pt.x2);
		ft_swap(&pt.y1, &pt.y2);
	}
	a = ((float)(pt.y2 - pt.y1) / (pt.x2 - pt.x1));
	while (i < (int)pt.dx + 1)
	{
		if (pt.x1 + i > 0 && pt.x1 + i < env->win_w && (pt.y1
			+ (int)(i * a)) > 0 && (pt.y1 + (int)(i * a)) < env->win_h)
				env->img->datas[(pt.y1 + (int)(i * a)) * env->win_w +
				pt.x1 + i] = env->color;
		i++;
	}
}

void draw_column(int i, t_env *env)
{
	t_pt pt;

	pt.x1 = env->iso[i][1];
	pt.x2 = env->iso[i + 1][1];
	pt.y1 = env->iso[i][0];
	pt.y2 = env->iso[i + 1][0];
	pt.dx = abs(pt.x2 - pt.x1);
	pt.dy = abs(pt.y2 - pt.y1);
	if (pt.dx >= pt.dy && pt.dx != 0 && pt.dy != 0)
		case1(env, pt);

}

void draw(t_env *env)
{
	int i;
	int x;

	i = -1;
	x = 1;
	while (++i < env->map->x_max * env->map->y_max - 1)
	{
		if (i != (x * env->map->x_max) - 1)
			draw_column(i, env);
		else
			x++;

	}
}
