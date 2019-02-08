/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:45:16 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/08 18:21:04 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keymap.h"
#include "mlx.h"

/*https://openclassrooms.com/fr/courses/1389636-a-la-decouverte-de-laleatoire-et-des-probabilites/1389794-fabriquez-votre-propre-fonction-rand*/
// int		change_color(t_env *env)
// {
	

// }

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
	(code == PLUS) ? env->zoom += 1 : 0;
	(code == MINUS) ? env->zoom -= 1 : 0;
	// (code == C) ? env->color = change_color(env) : 0;
	mlx_clear_window(env->mlx, env->window);
	refresh(env);
	return (0);
}

int		key_repeat(int key, t_env *env)
{
	(void)key;
	(void)env;
	return (0);
}