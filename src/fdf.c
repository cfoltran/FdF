/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/31 13:04:48 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parser.h"
#include "mlx.h"

int			init(t_env *env)
{
	env->mlx = mlx_init();
	window(env);
	env->window = mlx_new_window(env->mlx, env->win_w, env->win_h, env->name);
	mlx_key_hook(env->window, keylogger, 0);
	mlx(env);
	mlx_loop(env->mlx);
	return (0);
}

int			ft_fdf(char *argv)
{
	t_env env;
	t_map *map;
	int i;
	int j;

	map = fdf_parser(argv);
	env.map = map;
	i = -1;
	while (++i < map->x_max)
	{
		j = -1;
		while (++j < map->y_max)
			ft_putnbr(map->points[i][j]);
		ft_putendl("");
	}
	env.name = argv;
	init(&env);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	else
		ft_fdf(av[1]);
	return (0);
}
