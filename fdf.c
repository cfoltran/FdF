/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/28 13:32:07 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const **argv)
{
    (void) argv;
    (void) argc;
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "FdF");
    mlx_loop(mlx);
    return (0);
}
