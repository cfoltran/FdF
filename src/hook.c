/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:45:16 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/06 16:50:27 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keymap.h"

int     keylogger(int code)
{
    if (code == ESC)
        exit(0);
    return (0);
}

int     key_repeat(int key, t_env *env)
{
    (void) key;
    (void) env;
	return (0);
}