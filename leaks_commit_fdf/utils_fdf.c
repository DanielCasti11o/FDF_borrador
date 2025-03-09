/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:02 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/09 22:12:25 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg, int n)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	exit(n);
}

void	fr_ints(int **m_int, t_ejes *eje)
{
	int	i;
	int	len_y;

	i = 0;
	len_y = eje->len_y;
	while (i < eje->len_y)
	{
		free(m_int[i]);
		i++;
	}
	free(m_int);
}

void	fr_struct(t_ejes *eje)
{
	free(eje->len_x);
	free(eje->lines);
}
