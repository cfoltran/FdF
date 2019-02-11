/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:12:20 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/11 15:37:59 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

int		iso(t_env *env, int x, int y, int opt)
{
	int z;

	z = env->map->points[x][y];
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

void	init_iso_tab(t_map *map, t_env *env)
{
	int i;
	int **tab;

	i = -1;
	if (!(tab = (int**)malloc(sizeof(int*) * (map->x_max * map->y_max))))
		exit(1);
	while (++i < map->x_max * map->y_max)
		if (!(tab[i] = (int*)malloc(sizeof(int) * 2)))
			exit(1);
	env->iso = tab;
}

void	draw_column(int i, t_env *env)
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

void	draw(t_env *env)
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
