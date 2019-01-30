/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:30:05 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/30 19:32:42 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void    draw_segment(int x1, int y1, int x2, int y2, t_env *env)
{
	int dx;
	int dy;
	int e;
    (void) env;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(env->mlx, env->window, x1, y1, 0xFFFFFF);
		x1++;
		if ((e -= dy) <= 0)
		{
			y1++;
			e += dx;
		}
	}
}