/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/28 15:50:57 by cvignal          ###   ########.fr       */
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
	t_list	*points;

    if (ac != 2)
	{
		usage();
		return (1);
	}
	if (!(points = fdf_parser(av[1])))
		return (1);
    return (0);
}
