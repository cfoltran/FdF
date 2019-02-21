/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:45:16 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/21 17:37:30 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keymap.h"
#include "mlx.h"

void	update_relief(t_env *env, int opt)
{
	int x;
	int y;
	int z;

	x = -1;
	while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
			z = env->map->points[x][y];
			if (z != 0 && z + 3 != 0 && opt == 1)
				env->map->points[x][y] += 3;
			if (z != 0 && z - 3 != 0 && opt == 0)
				env->map->points[x][y] -= 3;
		}
	}

	int j = -1;
	for(int i = 0; i < env->map->x_max; i++)
	{
		j = -1;
		while (++j < env->map->y_max)
			printf (" %d ", env->map->points[i][j]);
		printf("\n");
	}
	
}

void	display_usage(t_env *env)
{
	int x;
	int y;

	x = WINDOW_X - 230;
	y = 20;
	mlx_string_put(env->mlx, env->window, x + 40, y, 0xFFFFFF,
	"--- COMMANDS ---");
	mlx_string_put(env->mlx, env->window, x + 40, y + 30, 0xFFFFFF,
	"Exit      Escape");
	mlx_string_put(env->mlx, env->window, x + 40, y + 60, 0xFFFFFF,
	"Move      Arrows");
	mlx_string_put(env->mlx, env->window, x + 40, y + 90, 0xFFFFFF,
	"Zoom      	+    -");
	mlx_string_put(env->mlx, env->window, x + 40, y + 120, 0xFFFFFF,
	"Relief    	R    E");
	mlx_string_put(env->mlx, env->window, x + 40, y + 150, 0xFFFFFF,
	"Color    	    C");
	mlx_string_put(env->mlx, env->window, x + 40, y + 180, 0xFFFFFF,
	"Isometric    I");
	mlx_string_put(env->mlx, env->window, x + 40, y + 210, 0xFFFFFF,
	"Parallel     P");
}

int		keylogger(int code, t_env *env)
{
	(code == ESC) ? exit(0) : 0;
	(code == RIGHT) ? env->movey += 10 : 0;
	(code == LEFT) ? env->movey -= 10 : 0;
	(code == DOWN) ? env->movex += 10 : 0;
	(code == UP) ? env->movex -= 10 : 0;
	(code == MINUS) ? env->zoom += 1 : 0;
	(code == PLUS) ? env->zoom -= 1 : 0;
	(code == R) ? update_relief(env, 1) : 0;
	(code == E) ? update_relief(env, 0) : 0;
	if (code == C)
		env->color = rand() % (((0xFFFF00 + 1) - 0x0000010) + 0xFFFFFF);
	mlx_clear_window(env->mlx, env->window);
	refresh(env);
	return (0);
}
