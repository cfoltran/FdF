/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/29 11:26:42 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parser.h"
#include "mlx.h"
#include <math.h>

// static void	usage(void)
// {
// 	ft_printf("usage : fdf file1\n");
// }

//  

static void	draw_segment(int x1, int y1, int x2, int y2)
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

int			main(int ac, char **av)
{
	// t_list	*points;
	(void) ac;
	(void) av;

	draw_segment(250, 250, 500, 500);

    // if (ac != 2)
	// {
	// 	usage();
	// 	return (1);
	// }
	// if (!(points = fdf_parser(av[1])))
	// 	return (1);
    return (0);
}
