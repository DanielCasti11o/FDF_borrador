/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:50:29 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/28 21:44:53 by dacastil         ###   ########.fr       */
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
	lines = init_map(fd, eje->len_y, eje->len_x, argv);
	if (!lines)
		fr_words(lines);
	eje->len_x = rest_len(eje->len_x, lines);
	eje->matx_z = matx_to_arr(lines, eje->len_y, eje->len_x);
	eje->x1 = 0;
	eje->y1 = 0;
	eje->pos_x = POS_INIT_X;
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

t_bress	*init_bress(int x, int y, int x1, int y1)
{
	t_bress	*new;

	new = malloc(sizeof (t_bress));
	new->dif_x = Vabs(x1 - x);
	new->dif_y = Vabs(y1 - y);
	new->m = max(new->dif_x, new->dif_y);
	new->dif_x *= 2;
	new->dif_y *= 2;
	return (new);
}
