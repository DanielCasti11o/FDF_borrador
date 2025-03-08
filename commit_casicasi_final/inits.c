/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:50:29 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/08 14:16:52 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ejes	*init_ejes(int fd, char **lines, char *argv)
{
	t_ejes	*eje;

	eje = malloc(sizeof(t_ejes));
	if (!eje)
		return (NULL);
	eje->len_y = count_lines(fd, argv);
	printf("longitud y %d\n", eje->len_y);
	eje->len_x = lengs(eje->len_y, fd, argv);
	lines = read_map(fd, eje->len_y, eje->len_x, argv);
	if (!lines)
		fr_words(lines);
	eje->len_x = rest_len(eje->len_x, lines);
	eje->matx_z = matx_to_arr(lines, eje->len_y, eje->len_x);
	eje->zoom = 3;
	eje->color = 0xFFFFFF;
	eje->pos_x = POS_INIT_X;
	eje->move_x = 0;
	eje->move_y = 0;
	eje->eje_rot_y = 0.8;
	eje->eje_rot_x = 0.8;
	eje->pos_y = POS_INIT_Y;
	eje->pos_x1 = 0;
	eje->pos_y1 = 0;
	return (eje);
}

t_coord	*init_coord(t_ejes *eje)
{
	t_coord	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_coord));
	new->x1 = malloc(eje->len_y * sizeof(int *));
	new->y1 = malloc(eje->len_y * sizeof(int *));
	while (i < eje->len_y)
	{
		new->x1[i] = malloc(eje->len_x[i] * sizeof(int));
		new->y1[i] = malloc(eje->len_x[i] * sizeof(int));
		if (!new->x1[i] || !new->x1[i])
			return (NULL);
		i++;
	}
	return (new);
}

t_bress	*init_bress(int x, int y, float x1, float y1)
{
	t_bress	*new;

	new = malloc(sizeof (t_bress));
	new->dif_x = x1 - x;
	new->dif_y = y1 - y;
	new->m = round(max(Vabs(new->dif_x), Vabs(new->dif_y)));
	new->dif_x /= new->m;
	new->dif_y /= new->m;
	return (new);
}
