/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:53:23 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/05 16:00:47 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include <stdlib.h>
# include "parser.h"

# define WINDOW_X 1024
# define WINDOW_Y 800

typedef struct      s_img {
    char            *datas;
    void            *image;
    int             bpp;
    int             s_line;
    int             endian;
}                   t_img;

typedef struct      s_env {
    void            *window;
    void            *mlx;
    char            *name;
    int             win_w;
    int             win_h;
    int             zoom;
    t_map           *map;
    t_img           *img;
}                   t_env;

void    window(t_env *env);
int     keylogger(int code);
void    draw_segment(int x1, int y1, int x2, int y2, t_env *env);
void    img_init(t_env *env, t_img *img);
int     **isometric_chart(t_env *env);
void    draw(t_env *env);


#endif
