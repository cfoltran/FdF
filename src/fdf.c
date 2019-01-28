/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/28 18:03:00 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parser.h"
#include "mlx.h"

static void	usage(void)
{
	ft_printf("usage : fdf file1\n");
}

int main(int ac, char **av)
{
	t_map	*map;
	int		i;
	int		j;

    if (ac != 2)
	{
		usage();
		return (1);
	}
	if (!(map = fdf_parser(av[1])))
	{
		ft_printf("ERROR");
		return (1);
	}
	i = 0;
	while (i < map->x_max)
	{
		j = 0;
		while (j < map->y_max)
			ft_printf("%d ", map->points[i][j++]);
		ft_printf("\n");
		i++;
	}
    return (0);
}
