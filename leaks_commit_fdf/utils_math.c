/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:29:03 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/09 17:10:36 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int difx, int dify)
{
	if (difx < dify)
		return (dify);
	else
		return (difx);
}

int	v_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_moves(t_ejes *eje)
{
	eje->pos_x += POS_INIT_X + eje->move_x;
	eje->pos_y += POS_INIT_Y + eje->move_y;
	eje->pos_x1 += POS_INIT_X + eje->move_x;
	eje->pos_y1 += POS_INIT_Y + eje->move_y;
}

// Identify point Z, zoom and Isometric

void	ft_isometric(t_ejes *eje)
{
	eje->z = eje->matx_z[(int)eje->pos_y][(int)eje->pos_x];
	eje->z1 = eje->matx_z[(int)eje->pos_y1][(int)eje->pos_x1];
	eje->pos_x *= eje->zoom;
	eje->pos_y *= eje->zoom;
	eje->pos_x1 *= eje->zoom;
	eje->pos_y1 *= eje->zoom;
	eje->pos_x = (eje->pos_x - eje->pos_y) * cos(eje->eje_rot_x);
	eje->pos_y = (eje->pos_x + eje->pos_y) * sin(eje->eje_rot_y) - eje->z;
	eje->pos_x1 = (eje->pos_x1 - eje->pos_y1) * cos(eje->eje_rot_x);
	eje->pos_y1 = (eje->pos_x1 + eje->pos_y1) * sin(eje->eje_rot_y) - eje->z1;
	ft_moves(eje);
}
