/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:25:01 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 10:46:53 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fdf.h"

int		par(t_env *env, int x, int y, int flag)
{
	int z;

	z = env->map->points[x][y];
	if (flag)
		return ((x * 1 / tan(M_PI_4) * env->zoom + y * tan(M_PI_4) * env->zoom
				+ z * env->alt * -tan(M_PI_4) * env->zoom / 200 *
				env->map->x_max) + (env->win_h / 4));
	else
		return ((x * 1 / tan(M_PI_4) * env->zoom + y * tan(-M_PI_4) * env->zoom
				+ z * env->alt * tan(M_PI_4) * env->zoom / 200 *
				env->map->y_max) + (env->win_w / 2.25));
}

int		apply_par(t_env *env)
{
	int x;
	int y;
	int i;

	x = -1;
	i = -1;
	if (init_coord_tab(env->map, env))
		return (1);
	while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
			env->coord[++i][0] = par(env, x, y, 1);
			env->coord[i][1] = par(env, x, y, 0);
			env->coord[i][0] += env->movex;
			env->coord[i][1] += env->movey;
		}
	}
	return (0);
}
