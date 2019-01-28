/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:23:14 by clfoltra          #+#    #+#             */
/*   Updated: 2019/01/28 14:20:37 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     key_plus(int key, void *param)
{
    (void) key;
    (void) param;
    ft_putchar('+');
    return (0);
}

int     main(int argc, char const **argv)
{
    (void) argv;
    (void) argc;
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "FdF");
    mlx_pixel_put(mlx, window, 250, 250, 0xFFFFFF);
    mlx_key_hook(window, key_plus, (void*)0);
    mlx_loop(mlx);
    return (0);
}
