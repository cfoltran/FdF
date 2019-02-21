/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:12:20 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/21 16:52:47 by clfoltra         ###   ########.fr       */
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
		return (((x * cos(-1) * env->zoom + y * cos(1) * env->zoom + z
		* cos(-1)) + (env->win_h / 4)));
	else
		return (((x * sin(-1) * env->zoom + y * sin(1) * env->zoom + z 
		* 1 * sin(-3)) + (env->win_w / 2.25)));
}

void	init_iso_tab(t_map *map, t_env *env)
{
	int i;
	int **tab;

	i = -1;
	if (!(tab = (int**)malloc(sizeof(int*) * (map->x_max * map->y_max - 1))))
		errors(MEM);
	while (++i < map->x_max * map->y_max)
		if (!(tab[i] = (int*)malloc(sizeof(int) * 2)))
			errors(MEM);
	i = -1;
	if (env->iso)
	{
		while (++i < map->x_max * map->y_max)
			free(env->iso[i]);
		free(env->iso);
	}
	env->iso = tab;
}

void	draw_line(int i, t_env *env)
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
	if (pt.dx < pt.dy && pt.dx != 0 && pt.dy != 0)
		case2(env, pt);
	// if (pt.dx == 0)
	// 	case3(env, pt);
	// if (pt.dy == 0)
	// 	case4(env, pt);
}

void	draw_column(int i, t_env *env)
{
	t_pt pt;

	pt.x1 = env->iso[i][1];
	pt.x2 = env->iso[i + env->map->y_max][1];
	pt.y1 = env->iso[i][0];
	pt.y2 = env->iso[i + env->map->y_max][0];
	pt.dx = abs(pt.x2 - pt.x1);
	pt.dy = abs(pt.y2 - pt.y1);
	if (pt.dx >= pt.dy && pt.dx != 0 && pt.dy != 0)
		case1(env, pt);
	if (pt.dx < pt.dy && pt.dx != 0 && pt.dy != 0)
		case2(env, pt);
	// if (pt.dx == 0)
	// 	case3(env, pt);
	// if (pt.dy == 0)
	// 	case4(env, pt);
}

void	draw(t_env *env)
{
	int i;
	int	y;

	i = -1;
	y = 1;
	while (++i < env->map->x_max * env->map->y_max - 1)
	{
		if (i != (y * env->map->y_max) - 1)
			draw_line(i, env);
		else
			y++;
	}
	i = -1;
	while (++i < env->map->x_max * env->map->y_max - env->map->y_max)
		draw_column(i, env);
}
