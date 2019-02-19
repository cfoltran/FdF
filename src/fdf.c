/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/19 14:13:34 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mlx.h"
#include "fdf.h"

void	apply_iso(t_env *env)
{
	int x;
	int y;
	int i;

	x = -1;
	i = -1;
	init_iso_tab(env->map, env);
	while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
			env->iso[++i][0] = iso(env, x, y, 1);
			env->iso[i][1] = iso(env, x, y, 0);
			env->iso[i][0] += env->movex;
			env->iso[i][1] += env->movey;
		}
	}
}

void	refresh(t_env *env)
{
	t_img img;

	if (!(img.image = mlx_new_image(env->mlx, env->win_w, env->win_h)))
		errors(MLX);
	if (!(img.datas = (int *)mlx_get_data_addr(img.image, &img.bpp,
	&img.s_line, &img.endian)))
		errors(MLX);
	env->img = &img;
	apply_iso(env);
	draw(env);
	if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image
	, 0, 0)))
		errors(MLX);
	display_usage(env);
	mlx_destroy_image(env->mlx, env->img->image);
}

int		init(t_env *env)
{
	(!(env->mlx = mlx_init())) ? errors(MLX) : 0;
	if (!(env->window = mlx_new_window(env->mlx, env->win_w, env->win_h,
		env->name)))
		errors(MLX);
	refresh(env);
	(!(mlx_hook(env->window, 2, 5, keylogger, env))) ? errors(MLX) : 0;
	(!(mlx_loop(env->mlx))) ? errors(MLX) : 0;
	return (0);
}

int		ft_fdf(char *argv)
{
	t_env	env;
	t_map	*map;

	ft_strcmp(&argv[ft_strlen(argv) - 4], ".fdf") != 0 ? errors(ARG) : 0;
	if (!(map = fdf_parser(argv)))
		errors(3);
	env.movex = 0;
	env.movey = 0;
	env.map = map;
	env.name = ft_strjoin("FDF - ", argv);
	env.zoom = 20;
	env.color = 0xFFFFFF;
	env.win_w = WINDOW_X;
	env.win_h = WINDOW_Y;
	env.iso = NULL;
	init(&env);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		errors(1);
	else
		ft_fdf(av[1]);
	return (0);
}
