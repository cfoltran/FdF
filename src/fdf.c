/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/08 17:38:14 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parser.h"
#include "mlx.h"

int			init(t_env *env)
{
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, env->win_w, env->win_h, env->name);
	refresh(env);
	mlx_hook(env->window, 2, 5, keylogger, env);
	mlx_loop(env->mlx);
	return (0);
}

int			ft_fdf(char *argv)
{
	t_env	env;
	t_map	*map;

	map = fdf_parser(argv);
	env.movex = 0;
	env.movey = 0;
	env.map = map;
	env.name = argv;
	env.zoom = 10;
	env.color = 0xFFFFFF;
	env.win_w = WINDOW_X;
    env.win_h = WINDOW_Y;
	init(&env);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		errors(1);
	else
		ft_fdf(av[1]);
	return (0);
}
