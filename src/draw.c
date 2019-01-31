/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:22:10 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/31 13:03:52 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void    draw(t_env *env)
{

}

int     mlx(t_env *env)
{
    env->image = mlx_new_image(env->mlx, env->win_h, env->win_w);
    env->mlx_infos = mlx_get_data_addr(env->image, &env->bpp, &env->s_line, 
        &env->endian);
    draw_segment(100,200,1000,500, env);
    draw(env);
    ft_putstr(env->mlx_infos);
    return (0);
}