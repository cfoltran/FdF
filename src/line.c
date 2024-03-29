/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:27:33 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/25 11:06:06 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case1(t_env *env, t_pt pt)
{
	float	a;
	int		i;

	a = 0;
	i = 0;
	if (pt.x1 > pt.x2)
	{
		ft_swapint(&pt.x1, &pt.x2);
		ft_swapint(&pt.y1, &pt.y2);
	}
	a = ((float)(pt.y2 - pt.y1) / (pt.x2 - pt.x1));
	while (i <= pt.dx)
	{
		if (pt.x1 + i > 0 && pt.x1 + i < env->win_w && (pt.y1
				+ (int)(i * a)) > 0 && pt.y1 + (int)(i * a) < env->win_h)
			env->img->datas[(pt.y1 + (int)(i * a)) * env->win_w
										+ pt.x1 + i] = env->color;
		i++;
	}
}

void	case2(t_env *env, t_pt pt)
{
	float	a;
	int		i;

	a = 0;
	i = -1;
	if (pt.y1 > pt.y2)
	{
		ft_swapint(&pt.y1, &pt.y2);
		ft_swapint(&pt.x1, &pt.x2);
	}
	a = (float)(pt.x2 - pt.x1) / (pt.y2 - pt.y1);
	while (++i <= pt.dy)
	{
		if (pt.x1 + (int)(i * a) > 0 && (pt.x1 + (int)(i * a)) < env->win_w
			&& (pt.y1 + i) > 0 && pt.y1 + i < env->win_h)
			env->img->datas[(pt.y1 + i) * env->win_w
				+ (pt.x1 + (int)(i * a))] = env->color;
	}
}

void	case3(t_env *env, t_pt pt)
{
	int		i;

	if (pt.y1 > pt.y2)
		ft_swapint(&pt.y1, &pt.y1);
	i = pt.y1;
	while (++i <= pt.y2)
	{
		if (pt.x1 > 0 && pt.x1 < env->win_w && i > 0 && i < env->win_h)
			env->img->datas[i * env->win_w + pt.x1] = env->color;
	}
}

void	case4(t_env *env, t_pt pt)
{
	int		i;

	if (pt.x1 > pt.x2)
		ft_swapint(&pt.x1, &pt.x2);
	i = pt.x1;
	while (++i <= pt.x2)
	{
		if (i > 0 && i < env->win_w && pt.y1 > 0 && pt.y1 < env->win_h)
			env->img->datas[pt.y1 * env->win_w + i] = env->color;
	}
}
