/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/05 16:07:29 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parser.h"
#include "mlx.h"

int			init(t_env *env)
{
	t_img img;

	env->mlx = mlx_init();
	window(env);
	env->window = mlx_new_window(env->mlx, env->win_w, env->win_h, env->name);
	img_init(env, &img);
	// isometric_chart(env);
	draw(env);
	// mlx_put_image_to_window(env->mlx, env->window, env->img->datas, 0, 0);
	mlx_key_hook(env->window, keylogger, 0);
	mlx_loop(env->mlx);
	return (0);
}

int			ft_fdf(char *argv)
{
	t_env env;
	t_map *map;

	map = fdf_parser(argv);
	env.map = map;
	env.name = argv;
	env.zoom = 50;
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