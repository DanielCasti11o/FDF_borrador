/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:50:29 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/09 22:14:10 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ejes	*init_ejes(int fd, char *argv)
{
	t_ejes	*eje;

	eje = malloc(sizeof(t_ejes));
	if (!eje)
		return (NULL);
	eje->len_y = count_lines(fd, argv);
	printf("longitud y %d\n", eje->len_y);
	eje->len_x = lengs(eje->len_y, fd, argv, eje);
	if (!eje->len_x)
		ft_error("Error", 1);
	eje->lines = read_map(fd, eje->len_y, eje->len_x, argv);
	if (!eje->lines)
		return (free(eje->len_x), fr_words(eje->lines), NULL);
	eje->len_x = rest_len(eje->len_x, eje->lines);
	eje->matx_z = matx_to_arr(eje->lines, eje->len_y, eje->len_x);
	eje->zoom = 20;
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

t_bress	*init_bress(int x, int y, float x1, float y1)
{
	t_bress	*new;

	new = malloc(sizeof (t_bress));
	new->dif_x = x1 - x;
	new->dif_y = y1 - y;
	new->m = round(max(v_abs(new->dif_x), v_abs(new->dif_y)));
	new->dif_x /= new->m;
	new->dif_y /= new->m;
	return (new);
}
