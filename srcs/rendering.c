/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:02:09 by svilau            #+#    #+#             */
/*   Updated: 2016/07/01 15:59:12 by svilau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render(t_2d_p *ren_point, t_3d_p point)
{
	(*ren_point).x = (CONST * point.x - CONST2 * point.y)
		+ ORIGIN_X;
	(*ren_point).y = ORIGIN_Y - (point.z + CONST / 2 * point.x + CONST2 / 2 *
			point.y);
}
