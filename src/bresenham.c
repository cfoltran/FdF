/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:30:05 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/30 17:31:55 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_segment(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int e;
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "FdF");
	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx, window, x1, y1, 0xFFFFFF);
		x1++;
		if ((e -= dy) <= 0)
		{
			y1++;
			e += dx;
		}
	}
	mlx_loop(mlx);
}