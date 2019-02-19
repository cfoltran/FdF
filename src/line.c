/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:27:33 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/18 20:08:30 by clfoltra         ###   ########.fr       */
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
	while (i < pt.dx + 1)
	{
		if (pt.x1 + i > 0 && pt.x1 + i < env->win_w && (pt.y1 +
		(int)(i * a)) > 0 && pt.y1 + (int)(i * a) < env->win_h)
			env->img->datas[(pt.y1 + (int)(i * a)) * env->win_w
										+ pt.x1 + i] = env->color;
		i++;
	}
}
