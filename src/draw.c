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

void		display_usage(t_env *env)
{
	int		x;
	int		y;

	x = WINDOW_X - 220;
	y = 20;
	mlx_string_put(env->mlx, env->window, x + 40, y, 0xFFFFFF,
			"--- COMMANDS ---");
	mlx_string_put(env->mlx, env->window, x, y + 40, 0xFFFFFF,
			"     Exit       ESC");
}

void        img_init(t_env *env, t_img *img)
{
    img->image = mlx_new_image(env->mlx, env->win_w, env->win_h);
    display_usage(env);
    img->datas = mlx_get_data_addr(img->image, &img->bpp,
			&img->s_line, &img->endian);
    // mlx_destroy_image(env->mlx, env->img->image);
}

static int  iso(int x, int y, t_env *env)
{
    int z;

    z = env->map->points[x][y];
    return (1);
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
            env->map->points[x][0] = iso(x, y, env);
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
            if (env->map->points[x][y] > 0)
            {
                draw_line(env, y, x);
                draw_column(env, y, x);
            }
        }
	}
}
