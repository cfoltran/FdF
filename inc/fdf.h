/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:53:23 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/06 16:42:43 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include <stdlib.h>
# include "parser.h"

# define WINDOW_X 1024
# define WINDOW_Y 800

typedef struct      s_img {
    void           *image;
    int            *datas;
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
    int             pixels;
    int             color;
    t_map           *map;
    t_img           *img;
}                   t_env;

typedef struct      s_pt {
    int             x1;
    int             y1;
    int             x2;
    int             y2;
    int             dx;
    int             dy;
}                   t_pt;

void    window(t_env *env);
int     keylogger(int code);
void    draw_segment(int x1, int y1, int x2, int y2, t_env *env);
void    img_init(t_env *env, t_img *img);
int     **isometric_chart(t_env *env);
void    draw(t_env *env);
int	    key_repeat(int key, t_env *env);
void    refresh(t_env *env);

#endif
