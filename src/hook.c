/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:45:16 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/25 10:50:33 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keymap.h"
#include "mlx.h"

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
	"Zoom      +-SROLL");
	mlx_string_put(env->mlx, env->window, x + 40, y + 120, 0xFFFFFF,
	"Relief    	R    E");
	mlx_string_put(env->mlx, env->window, x + 40, y + 150, 0xFFFFFF,
	"Color    	    C");
	mlx_string_put(env->mlx, env->window, x + 40, y + 180, 0xFFFFFF,
	"Isometric    I");
	mlx_string_put(env->mlx, env->window, x + 40, y + 210, 0xFFFFFF,
	"Parallel     P");
}

int		scroll(int code, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (code == SRLUP)
		env->zoom += 1;
	else if (code == SRLDO)
		env->zoom -= 1;
	mlx_clear_window(env->mlx, env->window);
	if (refresh(env))
		return (1);
	return (0);
}

int		keylogger(int code, t_env *env)
{
	(code == ESC) ? exit(0) : 0;
	(code == RIGHT) ? env->movey -= 10 : 0;
	(code == LEFT) ? env->movey += 10 : 0;
	(code == DOWN) ? env->movex -= 10 : 0;
	(code == UP) ? env->movex += 10 : 0;
	(code == MINUS) ? env->zoom += 0.5 : 0;
	(code == PLUS) ? env->zoom -= 0.5 : 0;
	(code == R) ? env->alt += 0.1 : 0;
	(code == E) ? env->alt -= 0.1 : 0;
	(code == I) ? env->proj = 0 : 0;
	(code == P) ? env->proj = 1 : 0;
	if (code == C)
		env->color = rand() % (((0xFFFF00 + 1) - 0x0000010) + 0xFFFFFF);
	mlx_clear_window(env->mlx, env->window);
	if (refresh(env))
		return (1);
	return (0);
}
