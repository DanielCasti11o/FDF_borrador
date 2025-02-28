/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:23:39 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/28 16:52:39 by dacastil         ###   ########.fr       */
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

t_coord	*find_coord_iso(t_ejes *eje)
{
	t_coord	*coord;
	float	coor_x1;
	float	coor_y1;
	int		eje_y;
	int		eje_x;

	printf("entra\n");
	eje_y = 0;
	coord = init_coord(eje);
	while (eje_y < eje->len_y)
	{
		eje_x = 0;
		while (eje_x < eje->len_x[eje_y])
		{
			coor_x1 = (eje->pos_x - eje->pos_y) * cos(30);
			coor_y1 = (eje->pos_x + eje->pos_y) * sin(30) - eje->matx_z[eje_y][eje_x];
			coord->x1[eje_y][eje_x] = round(coor_x1);
			printf("redondeada x %d\n", coord->x1[eje_y][eje_x]);
			coord->y1[eje_y][eje_x] = round(coor_y1);
			printf("redondeada y %d\n", coord->y1[eje_y][eje_x]);
			eje_x++;
			eje->pos_x++;
		}
		eje_y++;
		eje->pos_y++;
	}
	return (coord);
}
