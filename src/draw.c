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

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void        img_init(t_env *env)
{
    env->image = mlx_new_image(env->mlx, env->win_h, env->win_w);
    env->mlx_infos = mlx_get_data_addr(env->image, &env->bpp, &env->s_line, 
        &env->endian);
}

int         **isometric_chart(t_env *env)
{
    int x;
    int y;

    x = -1;
    while (++x < env->map->x_max)
    {
        y = -1;
        while (++y < env->map->y_max)
            iso(&x, &y, env->map->points[x][y]);
        y++;
    }
    return (env->map->points);
}

void		draw_line(t_env *env, int x, int y)
{
    draw_segment(x * env->zoom, y * env->zoom, x * env->zoom, y * env->zoom, env);
}

void        draw_column(t_env *env, int x, int y)
{
    draw_segment(x * env->zoom, y * env->zoom, x * env->zoom, y * env->zoom, env);
}

void        draw(t_env *env)
{
    int x;
    int y;
    
    x = -1;
    while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
           draw_line(env, x, y);
           draw_column(env, x, y);
        }
	}
}
