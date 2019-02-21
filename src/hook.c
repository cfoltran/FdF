/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:45:16 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/21 16:51:08 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keymap.h"
#include "mlx.h"

void	update_relief(t_env *env, int opt)
{
	int x;
	int y;
	(void) opt;

	x = -1;
	while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
			if (env->map->points[x][y] != 0)
				env->map->points[x][y] += (opt == 0) ? -3 : 3;
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
	"Color    	   C");
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
