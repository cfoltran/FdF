/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/25 10:47:30 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mlx.h"
#include "fdf.h"

int		apply_iso(t_env *env)
{
	int x;
	int y;
	int i;

	x = -1;
	i = -1;
	if (init_coord_tab(env->map, env))
		return (1);
	while (++x < env->map->x_max)
	{
		y = -1;
		while (++y < env->map->y_max)
		{
			env->coord[++i][0] = iso(env, x, y, 1);
			env->coord[i][1] = iso(env, x, y, 0);
			env->coord[i][0] += env->movex;
			env->coord[i][1] += env->movey;
		}
	}
	return (0);
}

int		refresh(t_env *env)
{
	t_img img;

	if (!(img.image = mlx_new_image(env->mlx, env->win_w, env->win_h)))
		return (errors(MLX));
	if (!(img.datas = (int *)mlx_get_data_addr(img.image, &img.bpp,
	&img.s_line, &img.endian)))
		return (errors(MLX));
	env->img = &img;
	if (env->proj)
	{
		if (apply_par(env))
			return (1);
	}
	else
	{
		if (apply_iso(env))
			return (1);
	}
	draw(env);
	if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image
	, 0, 0)))
		return (errors(MLX));
	display_usage(env);
	mlx_destroy_image(env->mlx, env->img->image);
	return (0);
}

int		init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (errors(MLX));
	if (!(env->window = mlx_new_window(env->mlx, env->win_w, env->win_h,
		env->name)))
		return (errors(MLX));
	if (refresh(env))
		return (1);
	if (!(mlx_hook(env->window, 4, 0, scroll, env)))
		return (errors(MLX));
	if (!(mlx_hook(env->window, 2, 5, keylogger, env)))
		return (errors(MLX));
	if (!(mlx_loop(env->mlx)))
		return (errors(MLX));
	return (0);
}

int		ft_fdf(char *argv)
{
	t_env	env;
	t_map	*map;

	if (!ft_strequ(&argv[ft_strlen(argv) - 4], ".fdf"))
		return (errors(ARG));
	if (!(map = fdf_parser(argv)))
		return (errors(ARG));
	env.movex = 0;
	env.movey = 0;
	env.alt = 0;
	env.map = map;
	if (!(env.name = ft_strjoin("FDF - ", argv)))
		return (errors(MEM));
	env.zoom = 20;
	env.proj = 0;
	env.color = 0xFFFFFF;
	env.win_w = WINDOW_X;
	env.win_h = WINDOW_Y;
	env.coord = NULL;
	env.proj = 0;
	if (init(&env))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_dprintf(2, "Usage : %s <filename>", av[0]);
		return (1);
	}
	else if (ft_fdf(av[1]))
		return (1);
	return (0);
}
