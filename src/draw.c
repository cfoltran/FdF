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
    img->datas = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->s_line, &img->endian);
}

void       refresh(t_env *env)
{
    t_img img;

    img.image = mlx_new_image(env->mlx, env->win_w, env->win_h);
    img.datas = (int *)mlx_get_data_addr(img.image, &img.bpp,
			 &img.s_line, &img.endian);
    env->img = &img;
	draw(env);
    mlx_put_image_to_window(env->mlx, env->window,
		env->img->image, 0, 0);
    display_usage(env);
    mlx_destroy_image(env->mlx, env->img->image);

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
    // env->map->points = isometric_chart(env);
    while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
            draw_line(env, y, x);
            // draw_column(env, y, x);
        }
	}
}
