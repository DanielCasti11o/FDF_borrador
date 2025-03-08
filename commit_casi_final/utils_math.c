/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:29:03 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 05:29:51 by dacastil         ###   ########.fr       */
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

int	Vabs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_isometric(t_ejes *eje, int z, int z1)
{
	eje->pos_x = (eje->pos_x - eje->pos_y) * cos(eje->eje_rot_x);
	eje->pos_y = (eje->pos_x + eje->pos_y) * sin(eje->eje_rot_y) - z;
	eje->pos_x1 = (eje->pos_x1 - eje->pos_y1) * cos(eje->eje_rot_x);
	eje->pos_y1 = (eje->pos_x1 + eje->pos_y1) * sin(eje->eje_rot_y) - z1;
}
